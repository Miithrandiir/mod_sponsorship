//
// Created by Mithrandir on 03/03/2021.
//

#ifndef AZEROTHCORE_SPONSORSHIPGROUP_HPP
#define AZEROTHCORE_SPONSORSHIPGROUP_HPP

class SponsorshipGroup : public GroupScript {

public:

    SponsorshipGroup() : GroupScript("SponsorshipGroup") {}

    void OnAddMember(Group* /*group*/, uint64 /*guid*/) override;


};

#endif //AZEROTHCORE_SPONSORSHIPGROUP_HPP
