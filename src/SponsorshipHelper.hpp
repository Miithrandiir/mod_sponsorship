//
// Created by Mithrandir on 25/02/2021.
//

#ifndef AZEROTHCORE_SPONSORSHIPHELPER_HPP
#define AZEROTHCORE_SPONSORSHIPHELPER_HPP


class SponsorshipHelper {

public:

    static bool isRegisterAsGodfather(Player *player);

    static std::map<int/*godfather*/, std::map<int/*nephew*/, bool/*isActive*/>> sponsorship;
};


#endif //AZEROTHCORE_SPONSORSHIPHELPER_HPP
