#ifndef COSC1076_A3_POINT3D_H
#define COSC1076_A3_POINT3D_H

#include "Point.h"

class Point3D: public Point{
public:   
    // Construct a Point3D with all coordinates initialized to 0
    Point3D();

    // Construct a Point3D with coordinates initialized to x,y,z
    Point3D(double x, double y, double z);

    //Deconstructor
    virtual ~Point3D();

    // Return the l1-norm of the point
    // l1-norm = abs(x) + abs(y) + abs(z)
    double getL1Norm() const override;


    //PostCondition: Based on the 'dim' it returns a reference to the x or y
    double& operator[](const char dim) override;


private:
    /*                                           */
    /* DO NOT MOFIFY ANY CODE IN THIS SECTION    */
    /*                                           */
    
    double x; //x-coordinate
    double y; //y-coordinate
    double z; //z-coordinate
    
};

#endif //COSC1076_A3_POINT3D_H