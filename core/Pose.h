//
// Created by Joey Sorkin on 3/29/22.
//
#include <string>
#ifndef PATHER_POSE_H
#define PATHER_POSE_H


class Pose {
    double x,y,heading;
public:
    explicit Pose(double _x = 0, double _y = 0, double _heading = 0);
    std::string toString();
    double getX();
    double getY();
    double getH();
};


#endif //PATHER_POSE_H
