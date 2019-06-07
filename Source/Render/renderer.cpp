#include "renderer.h"

void Renderer::InitSDL(const char* Name, int xpos, int ypos, int width, int height, bool enableVsync){
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cout << "Failed to Init SDL2" << std::endl;
    }

    MainWindow = SDL_CreateWindow(Name, xpos, ypos, width, height, SDL_WINDOW_OPENGL);

    if(!MainWindow){
        std::cout << "Unable To Create Window" << std::endl;
    }

    MainContext = SDL_GL_CreateContext(MainWindow);

    // Basic Opengl attribute flags
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE); // Set OpenGL to newest version
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3); // Set Min and Max Version
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2); 
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1); // Double Buffering with 24bit z buffer set either 1 (Low Performance), 16, 32 (high performance)

    if(enableVsync){
        SDL_GL_SetSwapInterval(1); // Enable Vsync, 0 = No Vsync, 1 = Vsync, May or May not work -1 = Adapative Vsync
    } else {
        SDL_GL_SetSwapInterval(0);
    }
    
}

void Renderer::InitGlew(){
    GLenum res = glewInit();
    if(res != GLEW_OK){
        std::cout << stderr << " GLEW init Error: " << glewGetErrorString(res) << std::endl;
    }
}

void Renderer::RenderScene(){
    glClear(GL_COLOR_BUFFER_BIT);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glDrawArrays(GL_TRIANGLES, 0, 3); // Does the Actual Drawing
    glDisableVertexAttribArray(0);

    SDL_GL_SwapWindow(MainWindow);
}

void Renderer::CreateVertexBuffer(){
    Vector3f Vertices[3];
    Vertices[0] = Vector3f(-1.0f, -1.0f, 0.0f);
    Vertices[1] = Vector3f(1.0f, -1.0f, 0.0f);
    Vertices[2] = Vector3f(0.0f, 1.0f, 0.0f);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);

}

void Renderer::CleanupSDL(){
    SDL_GL_DeleteContext(MainContext);
    SDL_DestroyWindow(MainWindow);
    SDL_Quit();
}