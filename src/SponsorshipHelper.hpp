/*
 * Copyright (C) 2021+     Miithrandiir <https://github.com/Miithrandiir/sponsorship>, released under GNU AGPL v3 license: LICENSE-AGPL3.md
 */


#ifndef AZEROTHCORE_SPONSORSHIPHELPER_HPP
#define AZEROTHCORE_SPONSORSHIPHELPER_HPP

#include "Config.h"
#include "Player.h"

class SponsorshipHelper
{
public:
    static bool AreInSponsorship(Player* , Player*);
    static bool AreInSponsorship(uint32 , uint32);
    static bool CanBenefit(Player*, Player*);
    static std::vector<uint32> GetBuff();
    static std::vector<std::pair<uint32, uint32>> Cache;
};


#endif //AZEROTHCORE_SPONSORSHIPHELPER_HPP
