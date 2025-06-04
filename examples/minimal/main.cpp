#include "retro3d.h"
#include "backend/sdl_video_device.h"
#include "backend/sdl_input_device.h"
#include "backend/sdl_sound_device.h"
#include "backend/t3d_render_device.h"
#include "sprite_component.h"

int main()
{
    retro3d::Engine engine;

    engine.CreateRenderDevice<platform::T3DRenderDevice>();
    engine.CreateSoundDevice<platform::SDLSoundDevice>();
    engine.CreateInputDevice<platform::SDLInputDevice>();
    engine.CreateVideoDevice<platform::SDLVideoDevice>();

    engine.GetVideo()->CreateWindow(640, 480, false);
    engine.GetRenderer()->CreateRenderSurface(640, 480);
    engine.GetRenderer()->SetDepthClip(0.1f, 100.0f, 90.0f);

    retro3d::Entity* e = engine.SpawnEntity();
    e->AddComponent<examples::SpriteComponent>();

    engine.Run();
    return 0;
}
