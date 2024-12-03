cmake_minimum_required(VERSION 3.23)
project(3d_renderer_engine)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules)

set(SDL2_PATH "C:/SDL2-2.30.7/x86_64-w64-mingw32")
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(3d_renderer_engine main.cpp ui/SDLWindow.cpp ui/SDLWindow.h main.cpp core/primitives/line/Line.h core/Color.h core/primitives/line/DDA.cpp core/primitives/line/DDA.h core/Canvas.cpp core/Canvas.h core/primitives/line/Bresenham.cpp core/primitives/line/Bresenham.h core/primitives/line/MidPoint.cpp core/primitives/line/MidPoint.h core/ObjParser.cpp core/ObjParser.h core/model/Model.cpp core/model/Model.h core/model/Face.h core/vector/Vector.h core/Rastering/CloudRaster.cpp core/Rastering/CloudRaster.h core/matrix/Matrix4x4.h core/projection/PerspectiveProjection.cpp core/projection/PerspectiveProjection.h)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY})
