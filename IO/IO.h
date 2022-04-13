//
// Created by Joey Sorkin on 4/13/22.
//

#ifndef PATHER_IO_H
#define PATHER_IO_H

#include "concepts"
#include "../core/Path.h"
#include "../sciplot/sciplot.hpp"
#include "../PathTypes/Combined/Combined.h"
#include <fstream>
using namespace sciplot;


namespace IO {
        std::pair<double, double> getRange(Vec v);

        template <PathType P>
        void plotCurve(P p);

        template <PathType P>
        void embedCurveInFile(P p);
};




#endif //PATHER_IO_H
