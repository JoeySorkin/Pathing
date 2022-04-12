//
// Created by Joey Sorkin on 3/29/22.
//
#include <string>
#include <cmath>
#ifndef PATHER_POSE_H
#define PATHER_POSE_H


class Pose {
    double x,y,heading;

public:
    explicit Pose(double _x = 0, double _y = 0, double _heading = 0);
    std::string toString();
    [[nodiscard]] double getX() const;
    [[nodiscard]] double getY() const;
    [[nodiscard]] double getH() const;

    static double getDistance(Pose const& a, Pose const& b);
    [[nodiscard]] double getDistance(Pose const& b) const;

    Pose operator+(Pose const& pose) const;
    Pose operator-(Pose const& pose) const;
};


#endif //PATHER_POSE_H
