#include "event.h"

void Event::EventPoll(bool* running){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT){
            *running = false;
        }
        if(event.type == SDL_KEYDOWN){
            switch(event.key.keysym.sym){
                case SDLK_ESCAPE:
                    *running = false;
                    break;
            }
        }
    }
}
