//
// Created by Joey Sorkin on 4/8/22.
//

#ifndef PATHER_LINEAR_H
#define PATHER_LINEAR_H


#include "Path.h"

class Linear : public Path {


    Pose origin, destination;
    double m;
public:
    Pose pointFromT(double t) override;
    Linear(Pose start, Pose end);

    static double lerp(double a, double b, double t);
};


#endif //PATHER_LINEAR_H
