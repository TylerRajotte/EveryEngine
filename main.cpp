#include "renderer.h"
#include "shader.h"
#include "event.h"

// Todo
//     I think I should work toward removing the math3d dependancy
//     Reimplement all the code regarding VBO and add VAO
//     Shader Code should more or less stay the same but the frontend should change
//          Should return a pointer to the location of the compiled shader program
//     Revamp the total front end for interacting with the renderer 
//         Should be as simple as possible working with the front end 
//         Maybe specify your shaders and model and the renderer takes care of the rest
//     Also maybe implement the idea behind a gameobject that contains more than render code 
//     Above advocates for a really abstracted front end/functions to work with things 
//     I Also like the idea of using small programs like the vertex shader to controll functionality like sound or behaviour
//     Settings File Functionality and actually making it work

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