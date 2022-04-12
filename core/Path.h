//
// Created by Joey Sorkin on 3/31/22.
//

#ifndef PATHER_PATH_H
#define PATHER_PATH_H


#include "Pose.h"

class Path {
    virtual Pose pointFromT(double t) const = 0;
    virtual Pose derivativeFromT(double t) const = 0;
    virtual double getLength() const = 0;
};


#endif //PATHER_PATH_H
