//
// Created by Joey Sorkin on 3/31/22.
//

#include "QuinticSpline.h"
#include "iostream"
/*
 * returns a point at a t=
 * https://www.desmos.com/calculator/gfbiikwcmk :(
 */
Pose QuinticSpline::fof(double t) {
//std::cout << std::to_string(t) << std::endl;
  double oAx = 0; // idk
  double oAy = 0; // when
  double dAx = 0; // to use
  double dAy = 0; // these terms :(


   double h0 = 1 - 10 * pow(t,3) + 15 * pow(t,4) - 6 * pow(t,5);
   double h1 = t - 6 * pow(t,3) + 8 * pow(t,4) - 3 * pow(t,5);
   double h2 = 0.5 * pow(t, 3) - pow(t,4) + 0.5 * pow(t,5) ;
   double h3 = 0.5 * pow(t, 3)  - pow(t,4) + 0.5 * pow(t,5);
   double h4 = -4 * pow(t,3) + 7 * pow(t,4) - 3 * pow(t,5);
   double h5 = 10 * pow(t,3) - 15 * pow(t,4) + 6 * pow(t,5);



    printf("%s | %s \n", origin->toString().c_str(), destination->toString().c_str());
   double xp = h0 * origin->getX() + h1 * oVx + h2 * oAx + h3 * dAx + h4 * dVx + h5 * destination->getX();
   double yp = h0 * origin->getY() + h1 * oVy + h2 * oAy + h3 * dAy + h4 * dVy + h5 * destination->getY();

   Pose ct = Pose(xp, yp);
   return ct;
}

QuinticSpline::QuinticSpline(Pose& start, Pose& end) {


    origin = &start;
    destination = &end;

    d = Pose::getDistance(origin, destination);
    oVx = cos(origin->getH() * (M_PI/180.0)) * d;
    oVy = sin(origin->getH() * (M_PI/180.0)) * d;
    dVx = cos(destination->getH() * (M_PI/180.0)) * d;
    dVy = sin(destination->getH() * (M_PI/180.0)) * d;

}
