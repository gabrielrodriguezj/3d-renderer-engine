#include "sdl_window.h"
#include <stdio.h>
#include <iostream>

SDLWindow::SDLWindow(int width, int height) {
    this->windowWidth = width;
    this->windowHeight = height;

    if(SDL_Init(SDL_INIT_EVERYTHING) !=0){
        fprintf(stderr, "Error initializing SDL: %s\n", SDL_GetError());
    }

    // Use SDL to query what is the fullscreen maximum width and height
    SDL_DisplayMode displayMode;
    SDL_GetCurrentDisplayMode(
            0, // the device
            &displayMode
    );

    //Create a SDL window
    this->window = SDL_CreateWindow(
            "3D renderer engine", // title
            SDL_WINDOWPOS_CENTERED, //pos x
            SDL_WINDOWPOS_CENTERED, //pos y
            this->windowWidth, // width
            this->windowHeight, // height
            0
    );

    if(!this->window){
        fprintf(stderr, "Error creating SDL window: %s\n", SDL_GetError());
    }

    //Create a SDL renderer
    this->renderer = SDL_CreateRenderer(
            window,
            -1,
            0
    );
    if(!this->renderer){
        fprintf(stderr, "Error creating SDL renderer: %s\n", SDL_GetError());
    }

    // Creating a SDL texture that is used to display the color buffer
    this->colorBufferTexture = SDL_CreateTexture(
            renderer,
            SDL_PIXELFORMAT_RGBA32,
            SDL_TEXTUREACCESS_STREAMING,
            this->windowWidth,
            this->windowHeight
    );

    this->running = true;
}

SDLWindow::~SDLWindow() {
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

bool SDLWindow::isRunning() {
    return running;
}

void SDLWindow::destroy() {
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

void SDLWindow::update(Canvas canvas){
    // Copy the frame buffer to the texture
    SDL_UpdateTexture(
            colorBufferTexture,
            NULL, // No rectangle area to update. NULL indicates that update the entire texture
            canvas.getBuffer(), // the source, raw pixel data
            (int)(this->windowWidth * sizeof(uint32_t)) // The number of bytes in a row of pixel data
    );

    // Copy the texture (or portion) to the current rendering target
    SDL_RenderCopy(renderer,
                   colorBufferTexture,
                   NULL, // render the entire texture, no specific rectangle
                   NULL // the entire rendering target, no specific rectangle (section)
    );

    // update the window
    SDL_RenderPresent(renderer);
}
