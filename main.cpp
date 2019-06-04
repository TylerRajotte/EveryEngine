#include "renderer.h"
#include "shader.h"
#include "event.h"

Shader* shader = nullptr;
Renderer* renderer = nullptr;
Event* event = nullptr;

int main(int argc, char** argv){
    shader = new Shader();
    renderer = new Renderer();
    event = new Event();

    renderer->InitSDL("EveryEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, false);
    renderer->InitGlew();

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    renderer->CreateVertexBuffer();
    shader->CompileShaders();

    bool running = true;
    while(running){
        event->EventPoll(&running);
        renderer->RenderScene();
    }
    renderer->CleanupSDL();

    return 0;
}