#include "ui/sdl_window.h"
#include "core/obj_parser.h"
#include "core/transformation/transformation.h"
#include "core/projection/projection.h"
#include "core/projection/perspective.h"
#include "core/rendering/flat_fill.h"
#include "core/rendering/skelethon.h"

bool isRunning = false;

void processInput();
Model update(Model, TransformationCoefficients);
void render(SDLWindow*, Canvas, Model, Projection*, Renderer*);
void freeResources();

int main(int argc, char* argv[]) {

    // Initial test configuration
    RenderConfiguration configuration{
        .width = 800,
        .height = 600,
        .fov = 160,
        .znear = 100,
        .zfar = 0.01,
        .fps = 15
    };

    // Initial configuration of the transformation
    TransformationCoefficients transformations;
    transformations.translationZ = 5.0;

    auto frameTargetTime = (int)(1000.0/ configuration.fps);
    uint32_t previous_frame_time = 0;

    SDLWindow window(configuration.width, configuration.height);
    isRunning = window.isRunning();

    ObjParser parser;
    char *filename = argv[1];
    Model model = parser.readFile(filename);

    Renderer *renderer = new FlatFill();
    Canvas canvas(configuration.width, configuration.height);
    Projection *perspectiveProjection = new Perspective(configuration);

    while (isRunning){
        processInput();

        transformations.rotationX += 0.1;
        transformations.rotationY += 0.1;
        transformations.rotationZ += 0.1;

        Model m = update(model,transformations);
        render(&window,
               canvas,
               m,
               perspectiveProjection,
               renderer);

        // Guarantees that every frame is executed every FRAME_TARGET_TIME
        // Wait some time until the reach the target frame time in milliseconds
        int time_to_wait = (int)(frameTargetTime - (SDL_GetTicks() - previous_frame_time));

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

void processInput(){
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

Model update(Model model, TransformationCoefficients transformationCoefficients){
    Transformation transformer;
    auto transformedModel = transformer.transformModel(model, transformationCoefficients);
    return transformedModel;
}

void render(SDLWindow *window,
            Canvas canvas,
            Model model,
            Projection *projection,
            Renderer *renderer){

    canvas.drawGrid();
    renderer->render(canvas, model, projection);
    window->update(canvas);
    canvas.clear(0xFF000000);
}

// Free the resources that must be released before the application is closed.
void freeResources(){

}
