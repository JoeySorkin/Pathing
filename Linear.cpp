//
// Created by Joey Sorkin on 4/8/22.
//

#include "Linear.h"


Linear::Linear(Pose start, Pose end){
    origin = start;
    destination = end;
    m = (origin.getY() - destination.getY())/(origin.getX() - destination.getX());
}

double Linear::lerp(double a, double b, double t){
    return a + (b - a) * t;
}
Pose Linear::pointFromT(double t){
    double x = lerp(origin.getX(), destination.getX(), t);
    double y = m * (x - origin.getX()) + origin.getY();
    return Pose(x,y,0);
}