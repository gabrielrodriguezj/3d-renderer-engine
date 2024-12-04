cmake_minimum_required(VERSION 3.23)
project(3d_renderer_engine)

set(CMAKE_CXX_STANDARD 14)

add_executable(3d_renderer_engine main.cpp core/primitives/line/line.h core/color.h core/primitives/line/dda.cpp core/primitives/line/dda.h core/canvas.cpp core/canvas.h core/primitives/line/bresenham.cpp core/primitives/line/bresenham.h core/primitives/line/middle_point.cpp core/primitives/line/middle_point.h core/obj_parser.cpp core/obj_parser.h core/model/model.cpp core/model/model.h core/model/face.h core/vector/vector.h core/rasterization/cloud.cpp core/rasterization/cloud.h core/matrix/matrix.h core/projection/perspective.cpp core/projection/perspective.h core/config.h)

