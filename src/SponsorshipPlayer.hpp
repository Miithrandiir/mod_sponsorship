//
// Created by Mithrandir on 25/02/2021.
//

#ifndef AZEROTHCORE_SPONSORSHIPPLAYER_HPP
#define AZEROTHCORE_SPONSORSHIPPLAYER_HPP

#include "map"


class SponsorshipPlayer : public PlayerScript {

public:
    SponsorshipPlayer() : PlayerScript("SponsorshipPlayer") {}

    void OnGiveXP(Player* /*player*/, uint32& /*amount*/, Unit* /*victim*/) override;

};


#endif //AZEROTHCORE_SPONSORSHIPPLAYER_HPP
