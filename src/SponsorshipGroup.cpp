//
// Created by Mithrandir on 03/03/2021.
//
#include <Group.h>
#include "SponsorshipGroup.hpp"
#include "SponsorshipHelper.hpp"


void SponsorshipGroup::OnAddMember(Group * group, uint64 guid) {

    Player* playerAdded = sObjectAccessor->FindPlayer(guid);
    if(!playerAdded)
        return;

    for(const Group::MemberSlot& player : group->GetMemberSlots())
    {
        if(player.guid == guid)
            continue;

        Player* member = sObjectAccessor->FindPlayer(player.guid);

        if(!member)
            continue;

        if(SponsorshipHelper::areInSponsorship(playerAdded, member))
        {
            //@TODO ? buff or other
            std::cout << "test compile" << std::endl;
        }

    }

}


void AddSC_SponsorshipGroup()
{
    new SponsorshipGroup();
}