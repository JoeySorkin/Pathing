//
// Created by Joey Sorkin on 3/31/22.
//

#ifndef PATHER_PATH_H
#define PATHER_PATH_H

#include "math.h"
#include "Pose.h"
#include <vector>
class Path {
    [[nodiscard]] virtual Pose pointFromT(double t) const = 0;
    [[nodiscard]] virtual Pose derivativeFromT(double t) const = 0;
    [[nodiscard]] virtual Pose dubderivativeFromT(double t) const = 0;
    [[nodiscard]] virtual double getLength() const = 0;
    [[nodiscard]] virtual double getTfromDistance(double distance) = 0;
    [[nodiscard]] virtual Pose getOrigin() = 0;
    [[nodiscard]] virtual Pose getDestination() = 0;
public:
    double getCurvature(double t){
        Pose dt = derivativeFromT(t);
        Pose ddt = dubderivativeFromT(t);
        double numerator = dt.getX() * ddt.getY() - dt.getY() - ddt.getX();
        double denominator = pow((pow(dt.getX(), 2) + pow(dt.getY(), 2)),3/2);
        return numerator / denominator;
    }

    std::vector<Pose> getSpacedPoints(int n){
        std::vector<Pose> points;
        points.reserve(n);
        for(double dist = 0; dist <= getLength() - (getLength()/(n-1)); dist += getLength()/(n-1)){
            double tval = getTfromDistance(dist);
            points.push_back(pointFromT(tval));
        }
        points.push_back(getDestination());
        return points;
    }
};



#endif //PATHER_PATH_H
