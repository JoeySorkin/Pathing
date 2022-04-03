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
  double originaccelx = 0;
  double originaccely = 0;
  double destinationaccelx = 0;
  double destinationaccely = 0;

   double h0 = 1 - 10 * pow(t,3) +15 * pow(t,4) - 5 * pow(t,5);
   double h1 = t - 6 * pow(t,3) + 8 * pow(t,4) - 3 * pow(t,5);
   double h2 = 0.5 * pow(t, 3) - pow(t,4) + 0.5 * pow(t,5) ;
   double h3 = 0.5 * pow(t, 3)  - pow(t,4) + 0.5 * pow(t,5);
   double h4 = -4 * pow(t,3) + 7 * pow(t,4) - 3 * pow(t,5);
   double h5 = 10 * pow(t,3) - 15 * pow(t,4) + 6 * pow(t,5);

   double xp = h0 * origin.getX() + h1 * origin.getH() + h2 * originaccelx + h3 * destinationaccelx + h4 * destination.getH() + h5 * destination.getX();
   double yp = h0 * origin.getY() + h1 * origin.getH() + h2 * originaccely + h3 * destinationaccely + h4 * destination.getH() + h5 * destination.getY();

   Pose ct = Pose(xp, yp);
   return ct;
}

QuinticSpline::QuinticSpline(Pose start, Pose end) {
    origin = start;
    destination = end;
}
