//
// Created by Mithrandir on 25/02/2021.
//

#include "SponsorshipHelper.hpp"

std::vector<std::pair<uint32, uint32>> SponsorshipHelper::Cache;


bool SponsorshipHelper::areInSponsorship(Player *player1, Player *player2) {


    //By making a cache we avoid a huge workload on database
    auto it = std::find(Cache.begin(), Cache.end(), std::make_pair(player1->GetSession()->GetAccountId(), player2->GetSession()->GetAccountId()));
    if(it != Cache.end())
        return true;
    it = std::find(Cache.begin(), Cache.end(), std::make_pair(player2->GetSession()->GetAccountId(), player1->GetSession()->GetAccountId()));
    if(it != Cache.end())
        return true;


    QueryResult result = LoginDatabase.PQuery("SELECT * FROM sponsorship WHERE godfather = %u AND nephew = %u OR godfather = %u AND nephew = %u",
                                              player1->GetSession()->GetAccountId(),
                                              player2->GetSession()->GetAccountId(),
                                              player2->GetSession()->GetAccountId(),
                                              player1->GetSession()->GetAccountId());

    //TODO check date validity
    Cache.emplace_back(player1->GetSession()->GetAccountId(), player2->GetSession()->GetAccountId());

    return (result != nullptr);

}

bool SponsorshipHelper::canBenefit(Player * player1, Player *player2) {

    //Check IP
    QueryResult resultPlayer1 = LoginDatabase.PQuery("SELECT last_ip FROM account WHERE id = %u",
                                                     player1->GetSession()->GetAccountId());
    QueryResult resultPlayer2 = LoginDatabase.PQuery("SELECT last_ip FROM account WHERE id = %u",
                                                     player1->GetSession()->GetAccountId());

    if (resultPlayer1 == nullptr && resultPlayer2 == nullptr) {
        std::cout << "[Sponsorship] Attempt to read data from database, but no records found (Account id:"
                  << player1->GetSession()->GetAccountId() << " id: " << player2->GetSession()->GetAccountId() << " )"
                  << std::endl;
        return false;
    }

    Field *fieldsPlayer1 = resultPlayer1->Fetch();
    Field *fieldsPlayer2 = resultPlayer2->Fetch();
    std::string ipAddressP1 = fieldsPlayer1[0].GetString();
    std::string ipAddressP2 = fieldsPlayer2[0].GetString();

    return (ipAddressP1 != ipAddressP2);
}

bool SponsorshipHelper::areInSponsorship(uint32 player1, uint32 player2) {
    auto it = std::find(Cache.begin(), Cache.end(), std::make_pair(player1, player2));
    if(it != Cache.end())
        return true;
    it = std::find(Cache.begin(), Cache.end(), std::make_pair(player2, player1));
    if(it != Cache.end())
        return true;


    QueryResult result = LoginDatabase.PQuery("SELECT * FROM sponsorship WHERE godfather = %u AND nephew = %u OR godfather = %u AND nephew = %u",
                                              player1,
                                              player2,
                                              player2,
                                              player1);

    //TODO check date validity
    Cache.emplace_back(player1, player2);

    return (result != nullptr);
}
