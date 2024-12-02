cmake_minimum_required(VERSION 3.23)
project(3d_renderer_engine)

set(CMAKE_CXX_STANDARD 14)

add_executable(3d_renderer_engine main.cpp core/primitives/line/Line.h core/Color.h core/primitives/line/DDA.cpp core/primitives/line/DDA.h core/Canvas.cpp core/Canvas.h)

