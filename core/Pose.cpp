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

double Pose::getX() const {
    return x;
}
double Pose::getY() const {
    return y;
}
double Pose::getH() const {
    return heading;
}

double Pose::getDistance(Pose const& a,Pose const& b){
    return sqrt(pow((a.getX() - b.getX()), 2) + pow((a.getY() - b.getY()), 2));
}

double Pose::getDistance(Pose const& b) const {
    return Pose::getDistance(*this, b);
}

Pose Pose::operator+ (Pose const& pose) const{
    return Pose(getX() + pose.getX(), getY() + pose.getY());
}

Pose Pose::operator-(const Pose &pose) const {
    return Pose(getX() - pose.getX(), getY() - pose.getY());
}
