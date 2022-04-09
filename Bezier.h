//
// Created by Joey Sorkin on 4/3/22.
//

#ifndef PATHER_BEZIER_H
#define PATHER_BEZIER_H


#include "core/Pose.h"
#include "Path.h"
#include <cmath>
#include <vector>

class Bezier : public Path {
private:
    typedef struct cpoint_s {
        Pose pose;
        double magnitude;
    } cpoint_s_t;

    cpoint_s_t origin, destination;
    double Bx,By,Cx,Cy;
public:
    Bezier(Pose a, double amag, Pose b, double bmag);
    Pose pointFromT(double t) override;

    Pose derivativeFromT(double t);

    std::vector<Pose> integrator();
};


#endif //PATHER_BEZIER_H
