#pragma once

#include <memory>
#include <random>

#include <Eigen/Core>

namespace raytracing {
namespace math {

/** Singleton class for generating random numbers. **/
class Random {

    /** A random number generator. **/
    static std::mt19937_64 rng;

    /** The seed used to initialize the rng. **/
    static int seed;

public: 

    static void setSeed(int seed);

    /**
        @returns A uniformly random number within [0.0, 1.0)
    **/
    static double uniform();

    /**
        @returns A uniformly random number within [lower, upper)
    **/
    static double uniform(double lower, double upper);
    
    /**
        @return A uniformly random unit vector
    **/
    static Eigen::Vector3d uniform_unit_vector();

    /**
        Calculates a random vector that resides on the same hemisphere
        of the unit sphere as the provided vector.

        @param v The vector to match hemispheres.
        @returns A uniformly random unit vector on the same hemisphere
            as v.
    **/
    static Eigen::Vector3d uniform_unit_vector_on_hemisphere(
        const Eigen::Vector3d &v
    );

    /**
        @returns A uniformly random vector within [0.0, 1.0)
    **/
    static Eigen::Vector3d uniform_vector();
    
    /**
        @returns A uniformly random vector within [lower, upper)
    **/
    static Eigen::Vector3d uniform_vector(double lower, double upper);

};

}
}