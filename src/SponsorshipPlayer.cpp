/*
 * Copyright (C) 2021+     Miithrandiir <https://github.com/Miithrandiir/sponsorship>, released under GNU AGPL v3 license: LICENSE-AGPL3.md
 */


#include <Group.h>
#include "SponsorshipHelper.hpp"
#include "SponsorshipPlayer.hpp"
#include "Chat.h"
#include "Config.h"
#include "Log.h"

void SponsorshipPlayer::OnGiveXP(Player* player, uint32& amount, Unit*) {

    Group* group = player->GetGroup();
    if(group != nullptr) {
        for(const Group::MemberSlot& item : group->GetMemberSlots())
        {
            if(item.guid == player->GetGUID()) {
                continue;
            }

            Player* player2 = sObjectAccessor->FindPlayer(item.guid);
            if(SponsorshipHelper::areInSponsorship(player->GetSession()->GetAccountId(), player2->GetSession()->GetAccountId())) {
                std::cout << "default amount of xp : " << amount << std::endl;
                amount *= sConfigMgr->GetFloatDefault("Sponsorship.rateXp", 2.00f);
                return;
            }
        }
    }


}


void AddSC_SponsorshipPlayer()
{
    new SponsorshipPlayer();
}
