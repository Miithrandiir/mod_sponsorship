//
// Created by Mithrandir on 25/02/2021.
//

#include "SponsorshipHelper.hpp"


bool SponsorshipHelper::isRegisterAsGodfather(Player *player) {

    try{

        sponsorship.at(player->GetSession()->GetAccountId());

        return true;

    } catch(out_of_range& /*oor*/) {
        return false;
    }

}
