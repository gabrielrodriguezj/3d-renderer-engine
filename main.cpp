#include "ui/SDLWindow.h"

bool isRunning = false;

void processInput(void){
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE)
                isRunning = false;
    }
}

int main(int argc, char* argv[]) {
    SDLWindow window(800, 600);
    isRunning = window.isRunning();

    while (isRunning){
        processInput();
    }

    window.destroy();
    return 0;
}
