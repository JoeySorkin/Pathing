#include <iostream>
#include "core/Pose.h"
#include "sciplot/sciplot.hpp"
#include "PathTypes/Bezier/Bezier.h"
#include "PathTypes/Linear/Linear.h"
#include "PathTypes/Combined/Combined.h"

using namespace sciplot;

int main() {
    Pose posea = Pose(0,0, -90);
    Pose poseb = Pose(1,6, -270 * (M_PI/180.0));
    Pose posec = Pose(2,5);
    Bezier l1 = Bezier(posea, 4, poseb, 5);
    Linear l2 = Linear(poseb, posec);
    Combined combo = Combined(l1, l2);
//    Bezier bs = Bezier(posea, 0 ,poseb, -1);
    printf("LEN: %f", combo.getLength());

#ifdef PLOTPOINTS
    Vec t = linspace(0.0, 1, 200);
    Plot plot;
    plot.xlabel("x");
    plot.ylabel("y");
    plot.xrange(0.0, 12.0);
    plot.yrange(0.0, 12.0);
    plot.legend().atOutsideBottom().displayHorizontal().displayExpandWidthBy(2).fontName("Fira Code");
    Vec xs, ys;
    xs.resize(t.size());
    ys.resize(t.size());
    for(int tidx = 0; tidx < t.size(); tidx +=1){
        double tval = t[tidx];
        Pose tpose = combo.pointFromT(tval);
        xs[tidx] = tpose.getX();
        ys[tidx] = tpose.getY();
    }
    plot.drawCurve(xs, ys).label("Bezier Curve");



    //equapoints
//
//    Vec equaX, equaY;
//    equaX.resize(eqapoints.size());
//    equaY.resize(eqapoints.size());
//    for(int i = 0; i < eqapoints.size(); i++){
//        equaX[i] = eqapoints[i].getX();
//        equaY[i] = eqapoints[i].getY();
//    }
//    plot.drawPoints(equaX, equaY).pointSize(2).label("Equidistant");
    Figure fig = {{plot}};
    fig.title( posea.toString() + " --> " + poseb.toString()).fontName("Fira Code");
    fig.size(800,800);
    fig.show();
#endif
    return 0;
}