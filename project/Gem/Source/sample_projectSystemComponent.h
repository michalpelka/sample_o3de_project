
#pragma once

#include <AzCore/Component/Component.h>

#include <sample_project/sample_projectBus.h>

namespace sample_project
{
    class sample_projectSystemComponent
        : public AZ::Component
        , protected sample_projectRequestBus::Handler
    {
    public:
        AZ_COMPONENT_DECL(sample_projectSystemComponent);

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        sample_projectSystemComponent();
        ~sample_projectSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // sample_projectRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
