/*
 * Copyright (C) 2021+     Miithrandiir <https://github.com/Miithrandiir/sponsorship>, released under GNU AGPL v3 license: LICENSE-AGPL3.md
 */

#include <Group.h>
#include "SponsorshipGroup.hpp"
#include "SponsorshipHelper.hpp"
#include "Config.h"

void SponsorshipGroup::OnAddMember(Group * group, uint64 guid)
{
    Player* playerAdded = sObjectAccessor->FindPlayer(guid);
    if(!playerAdded)
        return;

    for(const Group::MemberSlot& player : group->GetMemberSlots())
    {
        if(player.guid == guid)
        {
            continue;
        }

        Player* member = sObjectAccessor->FindPlayer(player.guid);

        if(!member)
        {
            continue;
        }

        if(SponsorshipHelper::areInSponsorship(playerAdded, member))
        {
            std::vector<uint32> buffs = SponsorshipHelper::getBuff();
            std::cout << "size of buffs = " << buffs.size() << std::endl;

            for(uint32& buff : buffs)
            {
                member->AddAura(buff, member);
                playerAdded->AddAura(buff, playerAdded);
            }
        }
    }
}

void SponsorshipGroup::OnRemoveMember(Group * group, uint64 guid, RemoveMethod, uint64, const char *)
{
    Player* player2 = sObjectAccessor->FindPlayer(guid);

    if(player2 == nullptr)
    {
        return;
    }

    for(const Group::MemberSlot& playerGroup : group->GetMemberSlots())
    {
        Player* player = sObjectAccessor->FindPlayer(playerGroup.guid);
        if(player == nullptr) {
            continue;
        }

        if(SponsorshipHelper::areInSponsorship(player, player2))
        {
            std::vector<uint32> buffs = SponsorshipHelper::getBuff();

            for(uint32& buff : buffs)
            {
                player->RemoveAura(buff);
                player2->RemoveAura(buff);
            }
        }
    }
}


void AddSC_SponsorshipGroup()
{
    new SponsorshipGroup();
}
