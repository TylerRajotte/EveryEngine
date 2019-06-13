#ifndef WindowManager_H
#define WindowManager_H

#include "../dependancies.h"

class WindowManager{
    public:
        void InitSDL(const char* Name, int xpos, int ypos, int width, int height, bool enableVsync);
        void InitGlew();
        void CleanScreen();
        void SwapWindow();
        void CleanupSDL();

    private:
        SDL_Window* MainWindow;
        SDL_GLContext MainContext;
        GLuint VBO;
};

#endif