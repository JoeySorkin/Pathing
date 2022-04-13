//
// Created by Joey Sorkin on 4/3/22.
//

#include "Bezier.h"


Bezier::Bezier(Pose a, double amag, Pose b, double bmag) {
    origin = cpoint_s{.pose = a, .magnitude = amag};
    destination = cpoint_s{.pose = b, .magnitude = bmag};
    //define extra control points with trig
    Bx = origin.magnitude * cos(origin.pose.getH()) + origin.pose.getX();
    By = origin.magnitude * sin(origin.pose.getH()) + origin.pose.getY();
    Cx = destination.magnitude * cos(destination.pose.getH()) + destination.pose.getX();
    Cy = destination.magnitude * sin(destination.pose.getH()) + destination.pose.getY();
    calcLength();
}


Pose Bezier::pointFromT(double t) const {
    // Bernstein polynomials for cubic bezier splines
    double b1 = pow((1 - t), 3);
    double b2 = 3 * t * pow((1 - t), 2);
    double b3 = 3 * pow(t,2) * (1 - t);
    double b4 = pow(t, 3);
    // get parameters
    double bx = origin.pose.getX() * b1 + Bx * b2 + Cx  * b3 + destination.pose.getX() * b4;
    double by = origin.pose.getY() * b1 + By * b2 + Cy  * b3 + destination.pose.getY() * b4;

    return Pose(bx,by);
}


Pose Bezier::derivativeFromT(double t) const {
    double b1d = -3 *  pow((1 - t), 2);
    double b2d = 9 * pow(t,2) - 12 * t + 3;
    double b3d = 3 * (2 - 3 * t) * t;
    double b4d = 3 * pow(t, 2);

    double bxd = origin.pose.getX() * b1d + Bx * b2d + Cx  * b3d + destination.pose.getX() * b4d;
    double byd = origin.pose.getY() * b1d + By * b2d + Cy  * b3d + destination.pose.getY() * b4d;

    return Pose(bxd,byd);
}

Pose Bezier::dubderivativeFromT(double t) const {
    double b1dd = 6 - 6 * t;
    double b2dd = 6 * (3 * t - 2);
    double b3dd = 6 - 18 * t;
    double b4dd = 6 * t;

    double bxdd = origin.pose.getX() * b1dd + Bx * b2dd + Cx  * b3dd + destination.pose.getX() * b4dd;
    double bydd = origin.pose.getY() * b1dd + By * b2dd + Cy  * b3dd + destination.pose.getY() * b4dd;
    return Pose(bxdd,bydd);
}

double Bezier::getLength() const {
    return arcLength;
}
void Bezier::calcLength() {
    double sum = 0;
    double dt = 0.000001;
    distanceT_LUT.emplace_back(0,0);
    for(double t = 0; t < 1; t += dt){
        // trapezoidal integration
        double t_plus =  t + dt;
        Pose a = derivativeFromT(t);
        Pose b = derivativeFromT(t_plus);
        double arclength_b = sqrt((pow(b.getX(), 2) + pow(b.getY(), 2)));
        double arclength_a = sqrt((pow(a.getX(), 2) + pow(a.getY(), 2)));
        sum += (arclength_a + arclength_b)/2.0 * dt;
        distanceT_LUT.emplace_back(sum, t);
    }
    std::sort(distanceT_LUT.begin(), distanceT_LUT.end());
    arcLength = sum;
}


double Bezier::getTfromDistance(double distance){
    if(distance <= arcLength && distance >= 0.0) //check if it is a valid distance
    {
        for(int i = 0; i < distanceT_LUT.size() - 1; i++){
            if(distance >= distanceT_LUT[i].first && distanceT_LUT[i+1].first >= distance){
                if(distance == 0) return 0;
                double frac = (distance - distanceT_LUT[i].second) / (distance - distanceT_LUT[i+1].second);
                double val = Linear::lerp(distanceT_LUT[i].second, distanceT_LUT[i+1].second, frac);
                return val ;

            }
        }
    }
    return -1;
}
Pose Bezier::getOrigin() {
    return origin.pose;
}
Pose Bezier::getDestination() {
    return destination.pose;
}
//std::vector<Pose> Bezier::integrator(){
//    double lastMark = 0;
//    double markInterval = 0.1;
//    std::vector<Pose> marks ;
//    double sum = 0;
//    double dt = 0.000001;
//
//    marks.emplace_back(origin.pose);
//    for(double t = 0; t < 1; t += dt){
//        // trapezoidal integration
//        double t_plus =  t + dt;
//        Pose a = derivativeFromT(t);
//        Pose b = derivativeFromT(t_plus);
//        double arclength_b = sqrt((pow(b.getX(), 2) + pow(b.getY(), 2)));
//        double arclength_a = sqrt((pow(a.getX(), 2) + pow(a.getY(), 2)));
//        sum += (arclength_a + arclength_b)/2.0 * dt;
//
//        //checks how far we have traveled
//        if(sum - lastMark > markInterval){
//            marks.emplace_back(pointFromT(t));
//            printf("∆Sum = %f\n", sum-lastMark);
//            lastMark = sum;
//
//        }
//    }
//    marks.emplace_back(destination.pose);
//
//    return marks;
//}




//integration function -
/*
 * Trapizoidal
 * Every, x length achieved store the coordinates
 * FTC
 */
