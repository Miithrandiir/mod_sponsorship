//
// Created by Mithrandir on 03/03/2021.
//

#ifndef AZEROTHCORE_SPONSORSHIPGROUP_HPP
#define AZEROTHCORE_SPONSORSHIPGROUP_HPP

class SponsorshipGroup : public GroupScript {

public:

    SponsorshipGroup() : GroupScript("SponsorshipGroup") {}

    void OnAddMember(Group* /*group*/, uint64 /*guid*/) override;
    virtual void OnRemoveMember(Group* /*group*/, uint64 /*guid*/, RemoveMethod /*method*/, uint64 /*kicker*/, const char* /*reason*/) override;


};

#endif //AZEROTHCORE_SPONSORSHIPGROUP_HPP
