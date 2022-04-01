//
// Created by Joey Sorkin on 3/29/22.
//

#include "Pose.h"

Pose::Pose(double _x, double _y, double _heading){
    x = _x;
    y = _y;
    heading = _heading;
}
std::string Pose::toString(){
    return "( " + std::to_string(x) + " , " + std::to_string(y) + ") Θ: " + std::to_string(heading);
}

double Pose::getX() {
    return x;
}
double Pose::getY() {
    return y;
}

double Pose::getH() {
    return heading;
}

