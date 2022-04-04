//
// Created by Joey Sorkin on 4/3/22.
//

#ifndef PATHER_BEZIER_H
#define PATHER_BEZIER_H


#include "core/Pose.h"
#include <cmath>
class Bezier {
private:
    typedef struct cpoint_s {
        Pose pose;
        double magnitude;
    } cpoint_s_t;

    cpoint_s_t origin, destination;
public:
    Bezier(Pose a, double amag, Pose b, double bmag);
    Pose pointFromT(double t);
};


#endif //PATHER_BEZIER_H
