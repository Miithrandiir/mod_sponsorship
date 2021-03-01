//
// Created by Mithrandir on 25/02/2021.
//

#include "SponsorshipPlayer.hpp"
#include "Chat.h"
#include "SponsorshipHelper.hpp"
#include "Config.h"

void SponsorshipPlayer::OnLogin(Player *player) {

    //Adding account of the player in the helper
    if(!SponsorshipHelper::isRegisterAsGodfather(player)) {

        std::pair<int, std::vector<std::pair<int, bool>>> newItem = std::make_pair(player->GetSession()->GetAccountId(), std::vector<std::pair<int, bool>>());
        SponsorshipHelper::sponsorship.insert(newItem);
    }

    QueryResult result = LoginDatabase.PQuery("SELECT * FROM sponsorship WHERE nephew = %u", player->GetSession()->GetAccountId());

    do {
        Field* fields = result->Fetch();

        uint32 godfather = fields[0].GetUInt32();
        uint32 nephew = fields[1].GetUInt32();
        time_t date = time_t(fields[2].GetUInt32());
        bool isActive = (std::difftime(time(nullptr), date) < sConfigMgr->GetIntDefault("Sponsorship.maxDate", 90)*86400);



    } while(result->NextRow());
}


void AddSC_Sponsorship()
{
    new SponsorshipPlayer();
}