#ifndef Renderer_H
#define Renderer_H

#include "dependancies.h"

class Renderer{
    public:
        void InitSDL(const char* Name, int xpos, int ypos, int width, int height, bool enableVsync);
        void InitGlew();
        void CreateVertexBuffer();
        void RenderScene();
        void CleanupSDL();

    private:
        SDL_Window* MainWindow;
        SDL_GLContext MainContext;
        GLuint VBO;
};

#endif