#ifndef INC_3D_RENDERER_ENGINE_SDL_WINDOW_H
#define INC_3D_RENDERER_ENGINE_SDL_WINDOW_H

#include <SDL.h>
#include "../core/Canvas.h"

class SDLWindow {
private:
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Texture* colorBufferTexture = NULL;

    int windowWidth = 0;
    int windowHeight = 0;
    bool running = false;

public:
    SDLWindow(int, int);
    ~SDLWindow(void);
    bool isRunning(void);
    void destroy(void);
    void update(Canvas);
};

#endif //INC_3D_RENDERER_ENGINE_SDL_WINDOW_H
