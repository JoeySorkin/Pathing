#include <iostream>
#include <fstream>
#include "core/Pose.h"
#include "sciplot/sciplot.hpp"
#include "PathTypes/Bezier/Bezier.h"
#include "PathTypes/Linear/Linear.h"
#include "PathTypes/Combined/Combined.h"
#include "IO/IO.h"

int main() {
    Pose posea = Pose(0,0, -90, DEG);
    Pose poseb = Pose(1,6, -270, DEG);

    Bezier bs = Bezier(posea, 1 ,poseb, -1);
    IO::embedCurveInFile(bs);
    IO::plotCurve(bs);

    return 0;
}