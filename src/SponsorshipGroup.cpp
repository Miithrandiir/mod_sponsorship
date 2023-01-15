/*
 * Copyright (C) 2021+     Miithrandiir <https://github.com/Miithrandiir/sponsorship>, released under GNU AGPL v3 license: LICENSE-AGPL3.md
 */

#include "SponsorshipGroup.hpp"

void SponsorshipGroup::OnAddMember(Group * group, ObjectGuid guid)
{
    Player* playerAdded = ObjectAccessor::FindPlayer(guid);

    if(!playerAdded)
        return;

    for(const Group::MemberSlot& player : group->GetMemberSlots())
    {
        if(player.guid == guid)
        {
            continue;
        }

        Player* member = ObjectAccessor::FindPlayer(player.guid);

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

void SponsorshipGroup::OnRemoveMember(Group * group, ObjectGuid guid, RemoveMethod, ObjectGuid, const char *)
{
    Player* player2 = ObjectAccessor::FindPlayer(guid);
    if(!player2)
    {
        return;
    }

    for(const Group::MemberSlot& playerGroup : group->GetMemberSlots())
    {
        Player* player = ObjectAccessor::FindPlayer(playerGroup.guid);
        if(!player)
        {
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
