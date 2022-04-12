cmake_minimum_required(VERSION 3.20)
project(Pather)

set(CMAKE_CXX_STANDARD 20)
set(VERSION )

add_compile_definitions(PLOTPOINTS)
add_executable(Pather main.cpp core/Pose.cpp core/Path.h PathTypes/QSplines/QuinticSpline.cpp PathTypes/QSplines/QuinticSpline.h PathTypes/Bezier/Bezier.cpp PathTypes/Bezier/Bezier.h PathTypes/Linear/Linear.cpp PathTypes/Linear/Linear.h PathTypes/Combined/Combined.cpp PathTypes/Combined/Combined.h)
