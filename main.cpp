#include "ui/SDLWindow.h"
#include "core/ObjParser.h"
#include "core/Canvas.h"
#include "core/Rastering/CloudRaster.h"

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

void update(void){

}

void render(void){

}

int main(int argc, char* argv[]) {
    SDLWindow window(800, 600);
    isRunning = window.isRunning();

    Model model;
    ObjParser parser;
    CloudRaster cloud;

    Canvas canvas(800, 600);
    parser.readFile("C:\\Users\\gabri\\CLionProjects\\3d-renderer-engine\\assets\\models\\cube.obj", model);

    canvas.drawGrid();
    cloud.raster(canvas, model);
    window.update(canvas);

    while (isRunning){
        processInput();
        update();
        render();
    }

    window.destroy();
    return 0;
}
