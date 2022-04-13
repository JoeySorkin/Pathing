//
// Created by Joey Sorkin on 4/3/22.
//

#ifndef PATHER_BEZIER_H
#define PATHER_BEZIER_H


#include "../../core/Pose.h"
#include "../../core/Path.h"
#include "../Linear/Linear.h"
#include <map>
#include <cmath>
#include <vector>
#include <algorithm>
#define LUT_RESOLUTION 100
class Bezier : public Path {
private:
    typedef struct cpoint_s {
        Pose pose;
        double magnitude;
    } cpoint_s_t;

    cpoint_s_t origin, destination;
    double Bx,By,Cx,Cy;
    double arcLength;
    std::vector<std::pair<double,double>> distanceT_LUT;
public:
    Bezier(Pose a, double amag, Pose b, double bmag);
    Pose pointFromT(double t) const override;
    Pose derivativeFromT(double t) const override;
    double getLength() const override;
    void calcLength();
    Pose dubderivativeFromT(double t) const override;
    double getTfromDistance(double distance) override;

    Pose getOrigin() override;

    Pose getDestination() override;
};


#endif //PATHER_BEZIER_H
