#ifndef COSC1076_A3_POINT_H
#define COSC1076_A3_POINT_H


/*                                           */
/* This is an abstract class that describe   */
/* the general concepts of a point           */
/*                                           */

class Point {
public:
    virtual ~Point() {} // Virtual destructor for polymorphic behavior

    virtual double getL1Norm() const = 0; // Pure virtual function for L1 norm calculation
    virtual double& operator[](const char dim) = 0; // Pure virtual function for accessing coordinates
};


#endif //COSC1076_A3_POINT_H