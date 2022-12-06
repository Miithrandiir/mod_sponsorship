/*
 * Copyright (C) 2021+     Miithrandiir <https://github.com/Miithrandiir/sponsorship>, released under GNU AGPL v3 license: LICENSE-AGPL3.md
 */


#ifndef AZEROTHCORE_SPONSORSHIPPLAYER_HPP
#define AZEROTHCORE_SPONSORSHIPPLAYER_HPP

#include "map"
#include "ScriptMgr.h"


class SponsorshipPlayer : public PlayerScript {

public:
    SponsorshipPlayer() : PlayerScript("SponsorshipPlayer") {}

    void OnGiveXP(Player* /*player*/, uint32& /*amount*/, Unit* /*victim*/) override;

};


#endif //AZEROTHCORE_SPONSORSHIPPLAYER_HPP
