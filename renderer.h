#ifndef Renderer_H
#define Renderer_H

#include <iostream>
#include <fstream>
#include <string.h>
#include <assert.h>
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include "math_3d.h"

class Renderer{
    public:
        void InitSDL(const char* Name, int xpos, int ypos, int width, int height, bool enableVsync);
        void InitGlew();
        void CreateVertexBuffer();
        void RenderScene(GLuint* gScaleLocation);
        void CleanupSDL();

    private:
        SDL_Window* MainWindow;
        SDL_GLContext MainContext;
        GLuint VBO;
};

#endif