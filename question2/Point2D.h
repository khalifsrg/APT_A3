#ifndef COSC1076_A3_POINT2D_H
#define COSC1076_A3_POINT2D_H

#include "Point.h"

class Point2D: public Point{
public:    
    // Construct a Point2D with all coordinates initialized to 0
    Point2D();

    // Construct a Point2D with coordinates initialized to x,y
    Point2D(double x, double y);

    //Deconstructor
    ~Point2D();

    // Return the l1-norm of the point
    // l1-norm = abs(x) + abs(y)
    double getL1Norm() const;

    // Should return a reference to the correspoinding 
    // coordinate of the point
    // 'x' <- x-coordinate
    // 'y' <- y-coordinate
    double& operator[](const char dim);

private:
    /*                                           */
    /* DO NOT MOFIFY ANY CODE IN THIS SECTION    */
    /*                                           */
    
    double x; //x-coordinate
    double y; //y-coordinate
    
};

#endif //COSC1076_A3_POINT2D_H