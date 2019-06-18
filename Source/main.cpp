#include "dependancies.h"
#include "Render/windowmanager.h"
#include "gameobject.h"
#include "event.h"
#include "settingsloader.h"

// General Assumtions
//      Open World with enough terrain that it will be loaded in and out
//      Maybe computer generated terrain

// Todo
//     Revamp the total front end for interacting with the renderer 
//         Should be as simple as possible working with the front end 
//         Maybe specify your shaders and model and the renderer takes care of the rest
//     Also maybe implement the idea behind a gameobject that contains more than render code 
//     Above advocates for a really abstracted front end/functions to work with things 
//     I Also like the idea of using small programs like the vertex shader to controll functionality like sound or behaviour
//     Settings File Functionality and actually making it work
//     Add error handing to windowmanager or create a better error handing system as a whole
//     

// Maybe work on some form of a Object Manager for keeping track of all the various objects such as 
//     GameObject
//          AI
//          Sounds
//          Interactivity

// I dont know how nessary these are but I do them anyways
WindowManager* windowmanager = nullptr;
Event* event = nullptr;
GameObject* testobject = nullptr;
SettingsLoader* settingsloader = nullptr;

int main(int argc, char** argv){
    // Starting all the modules
    windowmanager = new WindowManager();
    event = new Event();
    testobject = new GameObject();
    settingsloader = new SettingsLoader();

    // Load Settings from settings.txt
    settingsloader->LoadSettings("settings.txt");

    // Window manager initalization
    windowmanager->InitSDL(settingsloader->WindowName.c_str(),
                           settingsloader->WindowXPos,
                           settingsloader->WindowYPos, 
                           settingsloader->WindowXSize, 
                           settingsloader->WindowYSize, 
                           settingsloader->EnableVsync);
    
    windowmanager->InitGlew();

    // Black background, don't know where else to put this
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    // Creating a gameobject
    testobject->Init(0);
    // Enable wireframe mode
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // Restrict framerate inital variables
    const int FPS = 60;
    const int FrameDelay = 1000/FPS;
    Uint32 FrameStart;
    int FrameTime;

    // Controls if the game is actually running
    bool running = true;
    // The main game loop
    while(running){
        FrameStart = SDL_GetTicks();

        // Check for events
        event->EventPoll(&running);

        windowmanager->CleanScreen();

        // Rendering the game object
        testobject->RenderObject();
        
        windowmanager->SwapWindow();

        // Change framerate if its running too fast
        FrameTime = SDL_GetTicks() - FrameStart;
        if(FrameDelay > FrameTime){
            SDL_Delay(FrameDelay - FrameTime);
        }
    }
    // SDL has some stuff that needs to be cleaned up at the end
    windowmanager->CleanupSDL();

    return 0;
}