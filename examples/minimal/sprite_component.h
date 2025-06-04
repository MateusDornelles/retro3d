#ifndef EXAMPLES_MINIMAL_SPRITE_COMPONENT_H
#define EXAMPLES_MINIMAL_SPRITE_COMPONENT_H

#include "retro3d.h"
#include "ecs/components/retro_transform_component.h"
#include "graphics/retro_model.h"

namespace examples
{

retro_component(SpriteComponent)
{
private:
    retro3d::SharedTransform m_transform;
    mtlShared<retro3d::Model> m_model;
protected:
    void OnSpawn(void) override
    {
        m_transform = GetObject()->AddComponent<retro3d::TransformComponent>()->GetTransform();
        m_model = retro3d::Model::Library.Fetch("Default.Plane.Model");
    }
    void OnUpdate(void) override
    {
        GetRenderer()->RenderSpritePlane(*m_model.GetShared(), m_transform->GetFinalMatrix(),
                                         retro3d::RenderDevice::LightMode_Dynamic);
    }
public:
    SpriteComponent(void) : mtlInherit(this), m_transform(), m_model() {}
};

}

#endif // EXAMPLES_MINIMAL_SPRITE_COMPONENT_H
