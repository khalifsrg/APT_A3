#include <exception>
#include <stdexcept>
#include "Point2D.h"
#include <iostream>

Point2D::Point2D() : x(0), y(0) {}

Point2D::Point2D(double x, double y) : x(x), y(y) {}

Point2D::~Point2D() {}

double Point2D::getL1Norm() const {
    return std::abs(x) + std::abs(y);
}

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

