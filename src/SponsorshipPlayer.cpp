//
// Created by Mithrandir on 25/02/2021.
//

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

            Player* player2 = sObjectAccessor->FindPlayer(item.guid);

            if(SponsorshipHelper::areInSponsorship(player->GetSession()->GetAccountId(), player2->GetSession()->GetAccountId()))
                amount *= sConfigMgr->GetFloatDefault("Sponsorship.rateXp", 1.00);
        }

    }


}


void AddSC_SponsorshipPlayer()
{
    new SponsorshipPlayer();
}
