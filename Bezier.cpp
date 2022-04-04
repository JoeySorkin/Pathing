//
// Created by Joey Sorkin on 4/3/22.
//

#include "Bezier.h"

Bezier::Bezier(Pose a, double amag, Pose b, double bmag) {
    origin = cpoint_s{.pose = a, .magnitude = amag};
    destination = cpoint_s{.pose = b, .magnitude = bmag};
}

// P(t)

Pose Bezier::pointFromT(double t){
    // Bernstein polynomials for cubic bezier splines
    double b1 = pow((1 - t), 3);
    double b2 = 3 * t * pow((1 - t), 2);
    double b3 = 3 * pow(t,2) * (1 - t);
    double b4 = pow(t, 3);

    // define extra control points using trig :)
    double Bx = origin.magnitude * cos(origin.pose.getH()) + origin.pose.getX();
    double By = origin.magnitude * sin(origin.pose.getH()) + origin.pose.getY();
    double Cx = destination.magnitude * cos(destination.pose.getH()) + destination.pose.getX();
    double Cy = destination.magnitude * sin(destination.pose.getH()) + destination.pose.getY();

    // get parameters
    double bx = origin.pose.getX() * b1 + Bx * b2 + Cx  * b3 + destination.pose.getX() * b4;
    double by = origin.pose.getY() * b1 + By * b2 + Cy  * b3 + destination.pose.getY() * b4;

    return Pose(bx,by);
}
