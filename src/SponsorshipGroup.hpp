/*
 * Copyright (C) 2021+     Miithrandiir <https://github.com/Miithrandiir/sponsorship>, released under GNU AGPL v3 license: LICENSE-AGPL3.md
 */

#include "Config.h"
#include <Group.h>
#include "ScriptMgr.h"
#include "SponsorshipHelper.hpp"

#ifndef AZEROTHCORE_SPONSORSHIPGROUP_HPP
#define AZEROTHCORE_SPONSORSHIPGROUP_HPP

class SponsorshipGroup : public GroupScript
{
public:

    SponsorshipGroup() : GroupScript("SponsorshipGroup") {}

    void OnAddMember(Group* /*group*/, ObjectGuid /*guid*/) override;
    void OnRemoveMember(Group* /*group*/, ObjectGuid /*guid*/, RemoveMethod /*method*/, ObjectGuid /*kicker*/, char const* /*reason*/) override;
};

#endif //AZEROTHCORE_SPONSORSHIPGROUP_HPP
