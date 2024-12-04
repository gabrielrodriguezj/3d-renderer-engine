#include "ui/sdl_window.h"
#include "core/obj_parser.h"
#include "core/rasterization/cloud.h"

bool isRunning = false;

// Free the resources that must be released before the application is closed.
void freeResources(){

}

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

    float frameTargetTime = (1000 / configuration.fps);
    uint32_t previous_frame_time = 0;

    SDLWindow window(configuration.width, configuration.height);
    isRunning = window.isRunning();

    Model model;
    ObjParser parser;
    Cloud cloud;

    Canvas canvas(configuration.width, configuration.height);
    char *filename = "C:\\Users\\gabri\\CLionProjects\\3d-renderer-engine\\assets\\models\\cube.obj";
    parser.readFile(filename, model);

    canvas.drawGrid();
    Perspective perspectiveProjection(configuration);
    cloud.raster(canvas, model, perspectiveProjection);

    window.update(canvas);

    while (isRunning){
        processInput();
        update();
        render();

        // Guarantees that every frame is executed every FRAME_TARGET_TIME
        // Wait some time until the reach the target frame time in milliseconds
        int time_to_wait = frameTargetTime - (SDL_GetTicks() - previous_frame_time);

        // Only delay execution if we are running too fast
        if(time_to_wait >0 && time_to_wait <= frameTargetTime){
            SDL_Delay(time_to_wait);
        }
        previous_frame_time = SDL_GetTicks();
    }

    window.destroy();
    freeResources();
    return 0;
}
