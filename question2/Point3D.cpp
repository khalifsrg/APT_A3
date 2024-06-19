#include "Point3D.h"
#include <exception>
#include <stdexcept>
#include <iostream>

/// @brief Constructors
Point3D::Point3D() : x(0), y(0), z(0) {}
Point3D::Point3D(double x, double y, double z) : x(x), y(y), z(z) {}

/// @brief Destructor
Point3D::~Point3D() {}

/// @brief Calculate the L1 Norm of a 3D Point
/// @return returns the sum of the absolute values of the x, y, and z
double Point3D::getL1Norm() const {
    return std::abs(x) + std::abs(y) + std::abs(z);
}

/// @brief returns the reference to the x, y, or z coordinates based on 'dim'
/// @param dim 
/// @return 
double& Point3D::operator[](const char dim) {
    switch (dim) {
        case 'x':
            return x;
        case 'y':
            return y;
        case 'z':
            return z;
        default:
            throw std::invalid_argument("Invalid dimension");
    }
}
