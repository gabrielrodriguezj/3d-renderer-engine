cmake_minimum_required(VERSION 3.23)
project(3d_renderer_engine)

set(CMAKE_CXX_STANDARD 14)

add_executable(3d_renderer_engine main.cpp core/primitives/line/line.h core/color.h core/primitives/line/dda.cpp core/primitives/line/dda.h core/canvas.cpp core/canvas.h core/primitives/line/bresenham.cpp core/primitives/line/bresenham.h core/primitives/line/middle_point.cpp core/primitives/line/middle_point.h core/obj_parser.cpp core/obj_parser.h core/model/model.cpp core/model/model.h core/model/face.h core/vector/vector2.h core/vector/vector3.h core/vector/vector4.h core/rendering/cloud.cpp core/rendering/cloud.h core/matrix/matrix.h core/projection/perspective.cpp core/projection/perspective.h core/config.h core/projection/projection.h core/rendering/renderer.h core/rendering/skelethon.cpp core/rendering/skelethon.h core/rendering/flat.cpp core/rendering/flat.h core/transformation/transformation.h core/transformation/transformation.cpp)

