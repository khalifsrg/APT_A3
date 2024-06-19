/*                                           */
/* DO NOT MOFIFY ANY CODE IN THIS FILE       */
/*                                           */

#include <exception>
#include <stdexcept>
#include <iostream>
#include <random>
#include <iomanip>

#include "PointMatrix.h"
#include "Point.h"
#include "Point2D.h"
#include "Point3D.h"

#define N_ROWS  10
#define N_COLS  10

#define COORD_LIMS_LOW -10
#define COORD_LIMS_HIGH 10

int main(){

    /*                                           */
    /* DO NOT MOFIFY ANY CODE IN THIS SECTION    */
    /*                                           */

    //Create an point matrix of 2D points
    PointMatrix<Point2D> pm2D(N_ROWS, N_COLS);

    //Initialize the points to random values
    Point2D p2D;
    std::random_device engine;
    //std::default_random_engine engine(10);
    std::uniform_real_distribution<double> real_dist(COORD_LIMS_LOW, COORD_LIMS_HIGH);
    for (int i = 0; i != N_ROWS; ++i) {
        for (int j = 0; j != N_COLS; ++j) {
            p2D['x'] = real_dist(engine);
            p2D['y'] = real_dist(engine);

            pm2D.set(i, j, p2D);
        }
    }
    
    // Print the l1-norm of each Point in matrix
    std::cout << "*** Printing 2D point l1-norm ***" << std::endl;
    for (int i = 0; i != N_ROWS; ++i) {
        for (int j = 0; j != N_COLS; ++j) {
            std::cout << std::scientific << std::setprecision(2)
                            << pm2D.get(i, j).getL1Norm() << " ";
        }
        std::cout << std::endl;
    }

    std::cout << " " << std::endl;


    //Create an point matrix of 3D points
    PointMatrix<Point3D> pm3D(N_ROWS, N_COLS);

    //Initialize the points to random values
    Point3D p3D;
    for (int i = 0; i != N_ROWS; ++i) {
        for (int j = 0; j != N_COLS; ++j) {
            p3D['x'] = real_dist(engine);
            p3D['y'] = real_dist(engine);
            p3D['z'] = real_dist(engine);
            pm3D.set(i, j, p3D);
        }
    }

    // Print the brightness of each pixel
    std::cout << "*** Printing 3D point l1-norm ***" << std::endl;
    for (int i = 0; i != N_ROWS; ++i) {
        for (int j = 0; j != N_COLS; ++j) {
            std::cout << std::setfill('0') << std::setw(3) 
                                << pm3D.get(i, j).getL1Norm() << " ";
        }
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}