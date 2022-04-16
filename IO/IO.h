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


template <PathType P>
void IO::plotCurve(P p) {

    //setup
    Vec t = linspace(0.0, 1, 200);
    Plot CurvePlot, CurvatPlot;
    CurvePlot.xlabel("x");
    CurvePlot.ylabel("y");
    CurvePlot.xrange(-1, 12.0);
    CurvePlot.yrange(-1, 12.0);
    CurvePlot.legend().atOutsideBottom().displayHorizontal().displayExpandWidthBy(2).fontName("Fira Code");
    CurvatPlot.xlabel("x");
    CurvatPlot.ylabel("y");
    //ranges defined later
    CurvatPlot.legend().atOutsideBottom().displayHorizontal().displayExpandWidthBy(2).fontName("Fira Code");

    //(x,y)
    Vec xs, ys;
    xs.resize(t.size());
    ys.resize(t.size());
    for(int tidx = 0; tidx < t.size(); tidx +=1){
        double tval = t[tidx];
        Pose tpose = p.pointFromT(tval);
        xs[tidx] = tpose.getX();
        ys[tidx] = tpose.getY();
    }
    CurvePlot.drawCurve(xs, ys).label("Bezier Curve");


    //eqa points
    std::vector<Pose> eqapoints = p.getSpacedPoints(5);
    Vec equaX, equaY;
    equaX.resize(eqapoints.size());
    equaY.resize(eqapoints.size());
    for(int i = 0; i < eqapoints.size(); i++){
        equaX[i] = eqapoints[i].getX();
        equaY[i] = eqapoints[i].getY();
    }
    CurvePlot.drawPoints(equaX, equaY).pointSize(2).label("Equidistant");


    Vec curvatXs, curvatYs;
    curvatXs.resize(t.size());
    curvatYs.resize(t.size());
    for(int tidx = 0; tidx < t.size(); tidx +=1){
        double tval = t[tidx];
        curvatXs[tidx] = tval;
        curvatYs[tidx] = p.getCurvature(tval);
    }
    std::pair<double,double> xrange = {0,1};
    std::pair<double,double> yrange = getRange(curvatYs);
    printf("\n-----------\n X: [%f, %f], Y: [%f, %f] ", xrange.first, xrange.second, yrange.first, yrange.second);
    CurvatPlot.xrange(xrange.first,  xrange.second);
    CurvatPlot.yrange(std::min(-1.0,2.0),std::max(1.0, yrange.second));
    CurvatPlot.drawCurve(curvatXs, curvatYs).label("Curvature");

    Figure fig = {{CurvePlot, CurvatPlot}};
    fig.title( p.getOrigin().toString() + " --> " + p.getDestination().toString()).fontName("Fira Code");
    fig.size(800,800);
    fig.show();
}

template <PathType P>
void IO::embedCurveInFile(P p) {
    printf("Embedding points to file...");
    std::ofstream fileout;
    fileout.open("/Users/joeysorkin/Desktop/Big Folder o' Programming.nosync/vex/Pather/POINTS.h");
    fileout << "#include <vector>\n";
    fileout << "const std::vector<std::pair<double, double>> WAYPOINTS = { ";
    for (Pose point : p.getSpacedPoints(100)){
        fileout << "\n\t{ " + std::to_string(point.getX()) + "," + std::to_string(point.getY()) + "},";
    }
    fileout << "\n};";
    fileout.close();
}

std::pair<double, double> IO::getRange(Vec v) {
    double minval = INFINITY;
    double maxval = -INFINITY;
    for(double val : v){
        maxval = std::max(val, maxval);
        minval = std::min(val, minval);
    }
    return {minval, maxval};
}





#endif //PATHER_IO_H
