//
// Created by Joey Sorkin on 3/31/22.
//

#ifndef PATHER_QUINTICSPLINE_H
#define PATHER_QUINTICSPLINE_H

#include "math.h"
#include "Path.h"

class QuinticSpline : Path {
    private:
        Pose origin, destination;
    public:
        QuinticSpline(Pose start, Pose end);
        Pose fof(double t);

};


#endif //PATHER_QUINTICSPLINE_H
