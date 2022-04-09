#include <iostream>
#include "core/Pose.h"
#include "QSplines/QuinticSpline.h"
#include "sciplot/sciplot.hpp"
#include "Bezier.h"

using namespace sciplot;

int main() {
    Pose posea = Pose(0,0, 45 * (M_PI/180.0));
    Pose poseb = Pose(1,1, 45 * (M_PI/180.0));
    Bezier bs = Bezier(posea, 0 ,poseb, 0);
    std::vector<Pose> eqapoints = bs.integrator();


    Vec t = linspace(0.0, 1, 200);
    Plot plot;
    plot.xlabel("x");
    plot.ylabel("y");
    plot.xrange(-0.2, 1.2);
    plot.yrange(-0.2, 1.2);
    plot.legend().atOutsideBottom().displayHorizontal().displayExpandWidthBy(2);
    Vec xs, ys;
    xs.resize(t.size());
    ys.resize(t.size());
    for(int tidx = 0; tidx < t.size(); tidx +=1){
        double tval = t[tidx];
        Pose tpose = bs.pointFromT(tval);
        xs[tidx] = tpose.getX();
        ys[tidx] = tpose.getY();
    }
    printf("%s", bs.derivativeFromT(0.5).toString().c_str());
    plot.drawCurve(xs, ys).label("Bezier Curve");



    //equapoints

    Vec equaX, equaY;
    equaX.resize(eqapoints.size());
    equaY.resize(eqapoints.size());
    for(int i = 0; i < eqapoints.size(); i++){
        equaX[i] = eqapoints[i].getX();
        equaY[i] = eqapoints[i].getY();
    }
    plot.drawPoints(equaX, equaY).pointSize(2).label("Equidistant");
    Figure fig = {{plot}};
    fig.title( posea.toString() + " --> " + poseb.toString());
    fig.size(1000,500);
    fig.show();

    return 0;
}