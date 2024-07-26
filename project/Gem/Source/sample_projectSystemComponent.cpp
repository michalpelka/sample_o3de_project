
#include <AzCore/Serialization/SerializeContext.h>

#include "sample_projectSystemComponent.h"

#include <sample_project/sample_projectTypeIds.h>

namespace sample_project
{
    AZ_COMPONENT_IMPL(sample_projectSystemComponent, "sample_projectSystemComponent",
        sample_projectSystemComponentTypeId);

    void sample_projectSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<sample_projectSystemComponent, AZ::Component>()
                ->Version(0)
                ;
        }
    }

    void sample_projectSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC_CE("sample_projectService"));
    }

    void sample_projectSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC_CE("sample_projectService"));
    }

    void sample_projectSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void sample_projectSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    sample_projectSystemComponent::sample_projectSystemComponent()
    {
        if (sample_projectInterface::Get() == nullptr)
        {
            sample_projectInterface::Register(this);
        }
    }

    sample_projectSystemComponent::~sample_projectSystemComponent()
    {
        if (sample_projectInterface::Get() == this)
        {
            sample_projectInterface::Unregister(this);
        }
    }

    void sample_projectSystemComponent::Init()
    {
    }

    void sample_projectSystemComponent::Activate()
    {
        sample_projectRequestBus::Handler::BusConnect();
    }

    void sample_projectSystemComponent::Deactivate()
    {
        sample_projectRequestBus::Handler::BusDisconnect();
    }
}
