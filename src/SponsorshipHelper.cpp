/*
 * Copyright (C) 2021+     Miithrandiir <https://github.com/Miithrandiir/sponsorship>, released under GNU AGPL v3 license: LICENSE-AGPL3.md
 */


#include "SponsorshipHelper.hpp"

std::vector<std::pair<uint32, uint32>> SponsorshipHelper::Cache;

bool SponsorshipHelper::AreInSponsorship(Player *player1, Player *player2)
{
    //By making a cache we avoid a huge workload on database
    auto it = std::find(Cache.begin(), Cache.end(), std::make_pair(player1->GetSession()->GetAccountId(), player2->GetSession()->GetAccountId()));
    if(it != Cache.end())
    {
        return true;
    }

    it = std::find(Cache.begin(), Cache.end(), std::make_pair(player2->GetSession()->GetAccountId(), player1->GetSession()->GetAccountId()));
    if(it != Cache.end())
    {
        return true;
    }

    QueryResult result = LoginDatabase.Query("SELECT * FROM sponsorship WHERE ((godfather = {} AND nephew = {}) OR (godfather = {} AND nephew = {})) AND begin <= NOW() + interval {} day",
                                              player1->GetSession()->GetAccountId(),
                                              player2->GetSession()->GetAccountId(),
                                              player2->GetSession()->GetAccountId(),
                                              player1->GetSession()->GetAccountId(),
                                              sConfigMgr->GetOption<uint32>("Sponsorship.durationDay",90));

    Cache.emplace_back(player1->GetSession()->GetAccountId(), player2->GetSession()->GetAccountId());

    return (result != nullptr && result->GetRowCount() > 0);
}

bool SponsorshipHelper::CanBenefit(Player * player1, Player *player2)
{
    //Check IP
    QueryResult resultPlayer1 = LoginDatabase.Query("SELECT last_ip FROM account WHERE id = {}",
                                                     player1->GetSession()->GetAccountId());
    QueryResult resultPlayer2 = LoginDatabase.Query("SELECT last_ip FROM account WHERE id = {}",
                                                     player1->GetSession()->GetAccountId());

    if (!resultPlayer1 && !resultPlayer2)
    {
        std::cout << "[Sponsorship] Attempt to read data from database, but no records found (Account id:"
                  << player1->GetSession()->GetAccountId() << " id: " << player2->GetSession()->GetAccountId() << " )"
                  << std::endl;
        return false;
    }

    Field *fieldsPlayer1 = resultPlayer1->Fetch();
    Field *fieldsPlayer2 = resultPlayer2->Fetch();
    std::string ipAddressP1 = fieldsPlayer1[0].Get<std::string>();
    std::string ipAddressP2 = fieldsPlayer2[0].Get<std::string>();

    return (ipAddressP1 != ipAddressP2);
}

bool SponsorshipHelper::AreInSponsorship(uint32 player1, uint32 player2)
{
    auto it = std::find(Cache.begin(), Cache.end(), std::make_pair(player1, player2));
    if(it != Cache.end())
    {
        return true;
    }

    it = std::find(Cache.begin(), Cache.end(), std::make_pair(player2, player1));
    if(it != Cache.end())
    {
        return true;
    }

    QueryResult result = LoginDatabase.Query("SELECT * FROM sponsorship WHERE ((godfather = {} AND nephew = {}) OR (godfather = {} AND nephew = {})) AND begin <= NOW() + interval {} day",
                                              player1,
                                              player2,
                                              player2,
                                              player1,
                                              sConfigMgr->GetOption<uint32>("Sponsorship.durationDay",90));

    Cache.emplace_back(player1, player2);

    return (result->GetRowCount() > 0);
}

std::vector<uint32> SponsorshipHelper::GetBuff()
{
    std::vector<uint32> buffs;

    std::string strBuffs = sConfigMgr->GetOption<std::string>("Sponsorship.buff", "");

    std::istringstream streamBuff(strBuffs);
    std::string value;

    while(std::getline(streamBuff, value, ';'))
    {
        if(value.empty())
        {
            continue;
        }

        try
        {
            buffs.push_back((uint32)stoul(value));
        }
        catch(std::invalid_argument& /*e*/)
        {
            std::cout << "[sponsorship] Error when reading AURA : " << value << std::endl;
        }
    }

    return buffs;
}
