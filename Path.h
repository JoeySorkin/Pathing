//
// Created by Joey Sorkin on 3/31/22.
//

#ifndef PATHER_PATH_H
#define PATHER_PATH_H


#include "core/Pose.h"

class Path {
    virtual Pose fof(double t) = 0;
};


#endif //PATHER_PATH_H
