#ifndef COSC1076_A3_POINT_H
#define COSC1076_A3_POINT_H


/*                                           */
/* This is an abstract class that describe   */
/* the general concepts of a point           */
/*                                           */

class Point {
public:
    virtual ~Point() {} // Virtual destructor to assist in polymorphic behaviour

    virtual double getL1Norm() const = 0; // Using pure virtual function to assist in L1 norm calculation
    virtual double& operator[](const char dim) = 0; // Using pure virtual function to assist in accessing coordinates
};


#endif //COSC1076_A3_POINT_H