//
// Created by Mithrandir on 25/02/2021.
//

#ifndef AZEROTHCORE_SPONSORSHIPHELPER_HPP
#define AZEROTHCORE_SPONSORSHIPHELPER_HPP


class SponsorshipHelper {
public:
    static bool areInSponsorship(Player* , Player*);
    static bool areInSponsorship(uint32 , uint32);
    static bool canBenefit(Player*, Player*);
    static std::vector<uint32> getBuff();
    static std::vector<std::pair<uint32, uint32>> Cache;

};


#endif //AZEROTHCORE_SPONSORSHIPHELPER_HPP
