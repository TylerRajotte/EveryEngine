#include "dependancies.h"
#include "Render/windowmanager.h"
#include "Render/shader.h"
#include "event.h"
#include "Render/modelloader.h"

// General Assumtions
//      Open World with enough terrain that it will be loaded in and out
//      Maybe computer generated terrain

// Todo
//     I think I should work toward removing the math3d dependancy
//     Reimplement all the code regarding VBO and add VAO
//     Revamp the total front end for interacting with the renderer 
//         Should be as simple as possible working with the front end 
//         Maybe specify your shaders and model and the renderer takes care of the rest
//     Also maybe implement the idea behind a gameobject that contains more than render code 
//     Above advocates for a really abstracted front end/functions to work with things 
//     I Also like the idea of using small programs like the vertex shader to controll functionality like sound or behaviour
//     Settings File Functionality and actually making it work
//     

// Maybe work on some form of a Object Manager for keeping track of all the various objects such as 
// Game Objects and Render Objects or just GameObjects



// Basic Idea 1:
//     GameObject
//          POS(X, Y, Z)
//          Scale(x, y, z)
//          Rotation(x, y, z) + Rotation Point (x, y, z)
//          DisplayName
//          ID
//          Action Object (Based on the Action Object) Action Objects should be independant of Gameobject
//      Render Object
//          Model
//          Texture
//          Fracture Shader
//          Vertex Shader
//      Action Object
//          AI
//          Sounds
//          Interactivity
//
// Basic Idea 2:
//     GameObject
//          POS(X, Y, Z)
//          Scale(x, y, z)
//          Rotation(x, y, z) + Rotation Point (x, y, z)
//          DisplayName
//          ID
//          AI
//          Sounds
//          Interactivity
//      Render Object
//          Model
//          Texture
//          Fracture Shader
//          Vertex Shader
//
// GameObjects Should be the building blocks of everything
//      Houses, Items, Props, Player


Shader* shader = nullptr;
WindowManager* windowmanager = nullptr;
Event* event = nullptr;
ModelLoader* modelloader = nullptr;

int main(int argc, char** argv){
    shader = new Shader();
    windowmanager = new WindowManager();
    event = new Event();
    modelloader = new ModelLoader();

    if (modelloader->OpenModel(0)){
        std::cout << "No Errors in ModelLoader" << std::endl;
    } else {
        return -1;
    }

    windowmanager->InitSDL("EveryEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, false);
    windowmanager->InitGlew();

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    windowmanager->CreateVertexBuffer();

    glUseProgram(shader->CompileShaders(0));

    bool running = true;
    while(running){
        event->EventPoll(&running);
        windowmanager->RenderScene();
    }
    windowmanager->CleanupSDL();

    return 0;
}