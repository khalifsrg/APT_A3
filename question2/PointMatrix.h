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
    /// @brief Constructs the Matrix based on a vector
    /// @param nRows 
    /// @param nCols 
    PointMatrix(int nRows, int nCols) {
        pMatrix.resize(nRows, std::vector<PointType*>(nCols, nullptr));
    }

    /// @brief Destructor
    ~PointMatrix() {
        clearMatrix();
    }

    /// @brief Retrieves the spcific pointer to the point at the specified row and column
    /// @param row Row index of the point to be retrieved
    /// @param col Column index of the point to be retrieved
    /// @return Pointer to the PointType object at the specified position
    /// @throws std::out_of_range if row or col are out of valid range.
    PointType* get(int row, int col) const {
        if (row < 0 || row >= pMatrix.size() || col < 0 || col >= pMatrix[0].size()) {
            throw std::out_of_range("Invalid row or column index");
        }
        return pMatrix[row][col];
    }

    /// @brief Sets the point at the row and column to a new PointType object
    /// @param row Row index of the point to be set
    /// @param col Column index of the point to be set
    /// @param p PointType object to set at the specified position
    /// @throws std::out_of_range if row or col are out of valid range.
    void set(int row, int col, const PointType& p) {
        if (row < 0 || row >= pMatrix.size() || col < 0 || col >= pMatrix[0].size()) {
            throw std::out_of_range("Invalid row or column index");
        }
        pMatrix[row][col] = new PointType(p);
    }

    /// @brief Clears the entire matrix through deallocation of memory for all PointType objects
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