/*
 * Copyright (C) 2021+     Miithrandiir <https://github.com/Miithrandiir/sponsorship>, released under GNU AGPL v3 license: LICENSE-AGPL3.md
 */

#include "ScriptMgr.h"

#ifndef AZEROTHCORE_SPONSORSHIPGROUP_HPP
#define AZEROTHCORE_SPONSORSHIPGROUP_HPP

class SponsorshipGroup : public GroupScript {

public:

    SponsorshipGroup() : GroupScript("SponsorshipGroup") {}

    void OnAddMember(Group* /*group*/, uint64 /*guid*/);
    void OnRemoveMember(Group* /*group*/, uint64 /*guid*/, RemoveMethod /*method*/, uint64 /*kicker*/, const char* /*reason*/);


};

#endif //AZEROTHCORE_SPONSORSHIPGROUP_HPP
