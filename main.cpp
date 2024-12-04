#include "ui/SDLWindow.h"
#include "core/ObjParser.h"
#include "core/Canvas.h"
#include "core/rasterization/Cloud.h"

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

    // Initial test configuration
    RenderConfiguration configuration{
        .width = 800,
        .height = 600,
        .fov = 160,
        .znear = 100,
        .zfar = 0.01,
        .fps = 60
    };

    SDLWindow window(configuration.width, configuration.height);
    isRunning = window.isRunning();

    Model model;
    ObjParser parser;
    Cloud cloud;

    Canvas canvas(configuration.width, configuration.height);
    parser.readFile("C:\\Users\\gabri\\CLionProjects\\3d-renderer-engine\\assets\\models\\cube.obj", model);

    canvas.drawGrid();
    Perspective perspectiveProjection(configuration);
    cloud.raster(canvas, model, perspectiveProjection);

    window.update(canvas);

    while (isRunning){
        processInput();
        update();
        render();
    }

    window.destroy();
    return 0;
}
