#include <exception>
#include <stdexcept>
#include "Point2D.h"
#include <iostream>

/// @brief Constructors
Point2D::Point2D() : x(0), y(0) {}
Point2D::Point2D(double x, double y) : x(x), y(y) {}

/// @brief Destructor
Point2D::~Point2D() {}

/// @brief Calculate the L1 Norm of a 2D Point
/// @return returns the sum of the absolute values of the x and y
double Point2D::getL1Norm() const {
    return std::abs(x) + std::abs(y);
}

/// @brief returns the reference to the x or y coordinates based on 'dim'
/// @param dim 
/// @return returns the reference
double& Point2D::operator[] (const char dim) {
    switch (dim) {
        case 'x':
            return x;
        case 'y':
            return y;
        default:
            throw std::invalid_argument("Invalid dimension");
    }
}

