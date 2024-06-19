#ifndef COSC1076_A3_POINT_H
#define COSC1076_A3_POINT_H


/*                                           */
/* This is an abstract class that describe   */
/* the general concepts of a point           */
/*                                           */

class Point{
public:    

    // get the l1 norm of point
    double getL1Norm() const;

    //[] operator to access a given coordinates of a point
    double& operator[](const char dim);

private:
    
};

#endif //COSC1076_A3_POINT_H