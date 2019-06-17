#include "windowmanager.h"

void WindowManager::InitSDL(const char* name, int xpos, int ypos, int width, int height, bool enableVsync){
    // Init SDL2
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cout << "Failed to Init SDL2" << std::endl;
    }

    // Create a window
    MainWindow = SDL_CreateWindow(name, xpos, ypos, width, height, SDL_WINDOW_OPENGL);

    // Error Checking
    if(!MainWindow){
        std::cout << "Unable To Create Window" << std::endl;
    }

    // Create context
    MainContext = SDL_GL_CreateContext(MainWindow);

    // Basic Opengl attribute flags
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE); // Set OpenGL to newest version
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3); // Set Min and Max Version
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2); 
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1); // Double Buffering with 24bit z buffer set either 1 (Low Performance), 16, 32 (high performance)

    // To make vsync toggleable
    if(enableVsync){
        SDL_GL_SetSwapInterval(1); // Enable Vsync, 0 = No Vsync, 1 = Vsync, May or May not work -1 = Adapative Vsync
    } else {
        SDL_GL_SetSwapInterval(0);
    }
    
}

void WindowManager::InitGlew(){
    // Init glew and check for errors
    GLenum res = glewInit();
    if(res != GLEW_OK){
        std::cout << stderr << " GLEW init Error: " << glewGetErrorString(res) << std::endl;
    }
}

void WindowManager::CleanScreen(){
    // Clears screen
    glClear(GL_COLOR_BUFFER_BIT);
}

void WindowManager::SwapWindow(){
    // Swap the buffers/window
    SDL_GL_SwapWindow(MainWindow);
}

void WindowManager::CleanupSDL(){
    // Some stuff that needs to be called on exit
    SDL_GL_DeleteContext(MainContext);
    SDL_DestroyWindow(MainWindow);
    SDL_Quit();
}