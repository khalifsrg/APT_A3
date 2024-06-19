#ifndef COSC1076_A3_POINT_MATRIX_H
#define COSC1076_A3_POINT_MATRIX_H

#include <vector>
#include <stdexcept>

#include "Point.h"
#include "Point2D.h"
#include "Point3D.h"

template <typename PointType>
class PointMatrix {
public:
    PointMatrix(int nRows, int nCols) {
        pMatrix.resize(nRows, std::vector<PointType*>(nCols, nullptr));
    }

    ~PointMatrix() {
        clearMatrix();
    }

    PointType* get(int row, int col) const {
        if (row < 0 || row >= pMatrix.size() || col < 0 || col >= pMatrix[0].size()) {
            throw std::out_of_range("Invalid row or column index");
        }
        return pMatrix[row][col];
    }

    void set(int row, int col, const PointType& p) {
        if (row < 0 || row >= pMatrix.size() || col < 0 || col >= pMatrix[0].size()) {
            throw std::out_of_range("Invalid row or column index");
        }
        // Create a new instance of PointType and assign it to matrix
        pMatrix[row][col] = new PointType(p);
    }

    void clearMatrix() {
        for (auto& row : pMatrix) {
            for (auto& point : row) {
                delete point;
            }
            row.clear();
        }
        pMatrix.clear();
    }

private:
    std::vector<std::vector<PointType*>> pMatrix;
};


#endif //COSC1076_A3_POINT_MATRIX_H