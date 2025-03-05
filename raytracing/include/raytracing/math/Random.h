#pragma once

#include <memory>
#include <random>

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
    static double uniform(double left, double right);

};

}
}