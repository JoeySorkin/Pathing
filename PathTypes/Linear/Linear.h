//
// Created by Joey Sorkin on 4/8/22.
//

#ifndef PATHER_LINEAR_H
#define PATHER_LINEAR_H


#include "../../core/Path.h"

class Linear : public Path {


    Pose origin, destination;
    double m;
public:

    Linear(Pose start, Pose end);
    Pose pointFromT(double t) const override;
    Pose derivativeFromT(double t) const override;
    double getLength() const override;
    static double lerp(double a, double b, double t);
};


#endif //PATHER_LINEAR_H
