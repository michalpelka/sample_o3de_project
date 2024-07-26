
#pragma once

#include <sample_project/sample_projectTypeIds.h>

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace sample_project
{
    class sample_projectRequests
    {
    public:
        AZ_RTTI(sample_projectRequests, sample_projectRequestsTypeId);
        virtual ~sample_projectRequests() = default;
        // Put your public methods here
    };

    class sample_projectBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using sample_projectRequestBus = AZ::EBus<sample_projectRequests, sample_projectBusTraits>;
    using sample_projectInterface = AZ::Interface<sample_projectRequests>;

} // namespace sample_project
