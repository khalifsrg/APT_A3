#ifndef COSC1076_A3_PONIT_MATRIX_H
#define COSC1076_A3_PONIT_MATRIX_H

#include <vector>
#include <stdexcept>

#include "Point.h"
#include "Point2D.h"
#include "Point3D.h"

class PointMatrix{
public:    
    //Construct a matrix with nRows (number of rows) and
    // nCols (number of columns).
    PointMatrix(int nRows, int nCols);

    //Deconstructor: should clear the matrix
    ~PointMatrix();

    //should return the point(Point2D or Point3D) at [row,col]
    ? get(int row, int col);

    //Set the point at (row,col) to p
    void set(int row, int col, ? p);

private:

    //Should be a vector of vector points (2D or 3D)
    std::vector<std::vector> pMatrix;
    
};

#endif //COSC1076_A3_IMAGE_H