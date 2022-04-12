//
// Created by Joey Sorkin on 4/8/22.
//

#include "Linear.h"


Linear::Linear(Pose start, Pose end){
    origin = start;
    destination = end;
}

double Linear::lerp(double a, double b, double t){
    return a + (b - a) * t;
}
Pose Linear::pointFromT(double t) const {
    double x = lerp(origin.getX(), destination.getX(), t);
    double y = lerp(origin.getY(), destination.getY(), t);
    return Pose(x,y,0);
}

Pose Linear::derivativeFromT(double t) const {
    return destination - origin;
}

double Linear::getLength() const {
    return origin.getDistance(destination);
}

