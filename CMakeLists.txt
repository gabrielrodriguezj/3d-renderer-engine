cmake_minimum_required(VERSION 3.23)
project(3d_renderer_engine)

set(CMAKE_CXX_STANDARD 14)

add_executable(3d_renderer_engine main.cpp core/primitives/line/Line.h core/Color.h core/primitives/line/DDA.cpp core/primitives/line/DDA.h core/Canvas.cpp core/Canvas.h core/primitives/line/Bresenham.cpp core/primitives/line/Bresenham.h core/primitives/line/MidPoint.cpp core/primitives/line/MidPoint.h core/ObjParser.cpp core/ObjParser.h core/model/Model.cpp core/model/Model.h core/model/Face.h core/vector/Vector.h core/Rastering/CloudRaster.cpp core/Rastering/CloudRaster.h core/matrix/Matrix4x4.h core/projection/PerspectiveProjection.cpp core/projection/PerspectiveProjection.h)

