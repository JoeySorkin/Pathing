#include <iostream>
#include "core/Pose.h"
#include "QSplines/QuinticSpline.h"
#include "sciplot/sciplot.hpp"
#include "Bezier.h"

using namespace sciplot;

int main() {
    Pose posea = Pose(0,0, 90 * (M_PI/180.0));
    Pose poseb = Pose(1,1, 0 * (M_PI/180.0));
    Bezier bs = Bezier(posea, 1 ,poseb, -1);

    Vec t = linspace(0.0, 1, 200);


    // Create a Plot object
    Plot plot;
    // Set the x and y labels
    plot.xlabel("x");
    plot.ylabel("y");

    // Set the x and y ranges
    plot.xrange(-0.2, 1.2);
    plot.yrange(-0.2, 1.2);

    // Set the legend to be on the bottom along the horizontal
    plot.legend()
            .atOutsideBottom()
            .displayHorizontal()
            .displayExpandWidthBy(2);
    Vec xs, ys;
    xs.resize(t.size());
    ys.resize(t.size());
    for(int tidx = 0; tidx < t.size(); tidx +=1){
        double tval = t[tidx];
        Pose tpose = bs.pointFromT(tval);
        xs[tidx] = tpose.getX();
        ys[tidx] += tpose.getY();
    }
//    std::cout << xs << "\n";
    // Plot sin(i*x) from i = 1 to i = 6
    plot.drawCurve(xs, ys).label("QS");
    // Show the plot in a pop-up window
    Figure fig = {{plot}};
    fig.title( posea.toString() + " --> " + poseb.toString());
    fig.size(1000,500);
    fig.show();

    return 0;
}