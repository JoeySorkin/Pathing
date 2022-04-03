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
    std::string sx = std::to_string((x));
    std::string sy = std::to_string((y));
    std::string sh = std::to_string((heading));
//    std::string sx = std::to_string(((int)(x * 100))/100);
//    sx.erase(sx.find_last_not_of('0') + 1, std::string::npos);
//    std::string sy = std::to_string(((int)(y * 100))/100);
//    sy.erase(sy.find_last_not_of('0') + 1, std::string::npos);
//    std::string sh = std::to_string(((int)(heading * 100))/100);
//    sh.erase(sh.find_last_not_of('0') + 1, std::string::npos);
    return "( " + sx + " , " + sy + ") Θ: " + sh;
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

