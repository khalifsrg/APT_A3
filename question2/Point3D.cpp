#include "Point3D.h"
#include <exception>
#include <stdexcept>
#include <iostream>

Point3D::Point3D() : x(0), y(0), z(0) {}
Point3D::Point3D(double x, double y, double z) : x(x), y(y), z(z) {}

Point3D::~Point3D() {}

double Point3D::getL1Norm() const {
    return std::abs(x) + std::abs(y) + std::abs(z);
}

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
