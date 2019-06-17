#include "event.h"

void Event::EventPoll(bool* running){
    // Get the event object
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        // Check for the quit button being pressed and turn off the main game loop
        if(event.type == SDL_QUIT){
            *running = false;
        }

        // Keyboard input
        if(event.type == SDL_KEYDOWN){
            switch(event.key.keysym.sym){
                // Use ESC to quit too
                case SDLK_ESCAPE:
                    *running = false;
                    break;
            }
        }
    }
}
