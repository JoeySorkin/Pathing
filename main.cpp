#include <iostream>
#include "core/Pose.h"
#include "QuinticSpline.h"

int main() {
    Pose posea = Pose(0,0, M_PI);
    Pose poseb = Pose(1,0.5, M_PI/2);
    QuinticSpline qs = QuinticSpline(posea,poseb);
    std::cout << qs.fof(0.1).toString() << std::endl;8560/2;
    return 0;
}