cmake_minimum_required(VERSION 3.23)
project(3d_renderer_engine)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules)

set(SDL2_PATH "C:/SDL2-2.30.7/x86_64-w64-mingw32")
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(3d_renderer_engine main.cpp ui/sdl_window.cpp ui/sdl_window.h core/primitives/line/line.h core/color.h core/primitives/line/dda.cpp core/primitives/line/dda.h core/canvas.cpp core/canvas.h core/primitives/line/bresenham.cpp core/primitives/line/bresenham.h core/primitives/line/middle_point.cpp core/primitives/line/middle_point.h core/obj_parser.cpp core/obj_parser.h core/model/model.cpp core/model/model.h core/model/face.h core/vector/vector2.h core/vector/vector3.h core/vector/vector4.h core/rendering/cloud.cpp core/rendering/cloud.h core/matrix/matrix.h core/projection/perspective.cpp core/projection/perspective.h core/config.h core/projection/projection.h core/rendering/renderer.h core/transformation/transformation.h core/transformation/transformation.cpp core/rendering/skelethon.cpp core/rendering/skelethon.h)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY})
