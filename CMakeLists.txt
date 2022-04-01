cmake_minimum_required(VERSION 3.20)
project(Pather)

set(CMAKE_CXX_STANDARD 14)

add_executable(Pather main.cpp core/Pose.cpp Path.h QuinticSpline.cpp QuinticSpline.h)
