cmake_minimum_required(VERSION 3.20)
project(Pather)

set(CMAKE_CXX_STANDARD 17)
set(VERSION )

add_executable(Pather main.cpp core/Pose.cpp Path.h QSplines/QuinticSpline.cpp QSplines/QuinticSpline.h Bezier.cpp Bezier.h)
