
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "sample_projectSystemComponent.h"

#include <sample_project/sample_projectTypeIds.h>

namespace sample_project
{
    class sample_projectModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(sample_projectModule, sample_projectModuleTypeId, AZ::Module);
        AZ_CLASS_ALLOCATOR(sample_projectModule, AZ::SystemAllocator);

        sample_projectModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                sample_projectSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<sample_projectSystemComponent>(),
            };
        }
    };
}// namespace sample_project

#if defined(O3DE_GEM_NAME)
AZ_DECLARE_MODULE_CLASS(AZ_JOIN(Gem_, O3DE_GEM_NAME), sample_project::sample_projectModule)
#else
AZ_DECLARE_MODULE_CLASS(Gem_sample_project, sample_project::sample_projectModule)
#endif
