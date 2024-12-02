#ifndef INC_3D_RENDERER_ENGINE_SDLWINDOW_H
#define INC_3D_RENDERER_ENGINE_SDLWINDOW_H

#include <SDL.h>

class SDLWindow {
private:
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Texture* color_buffer_texture = NULL;
    uint32_t* color_buffer = NULL; // Some books like to call this as "frame buffer." For all practical purposes, color buffer & frame buffer are the same thing; they are a mirror in memory of the pixels that we want to see in our display.
    int windowWidth = 0;
    int windowHeight = 0;
    bool running = false;

public:
    SDLWindow(int, int);
    ~SDLWindow(void);
    bool isRunning(void);
    void destroy(void);
};

#endif //INC_3D_RENDERER_ENGINE_SDLWINDOW_H
