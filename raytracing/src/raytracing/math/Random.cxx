#include <raytracing/math/Random.h>

namespace raytracing {
namespace math {

static std::random_device dev;
int Random::seed = dev();
std::mt19937_64 Random::rng(Random::seed);

void Random::setSeed(int seed) {
    Random::seed = seed;
    Random::rng = std::mt19937_64(seed);
}

Eigen::Vector3d Random::uniform_unit_vector() {

    while(true) {
        Eigen::Vector3d p = Random::uniform_vector(-1.0, 1.0);
        double p_norm = p.norm();
        double sqr_p_norm = p_norm * p_norm;
        if(1e-160 < sqr_p_norm && sqr_p_norm <= 1) {
            return p / p_norm;
        }
    }

}

Eigen::Vector3d Random::uniform_unit_vector_on_hemisphere(
    const Eigen::Vector3d &v
) {
    Eigen::Vector3d result = Random::uniform_unit_vector();
    if(result.dot(v) >= 0.0) {
        return result;
    } else {
        return -result;
    }
}
    
double Random::uniform() {
    return Random::uniform(0.0, 1.0);
}

double Random::uniform(double lower, double upper) {
    std::uniform_real_distribution<double> dist(lower, upper);
    return dist(Random::rng);
}

Eigen::Vector3d Random::uniform_vector() {
    return Random::uniform_vector(0.0, 1.0);
}

Eigen::Vector3d Random::uniform_vector(double lower, double upper) {
    return Eigen::Vector3d(
        Random::uniform(lower, upper),
        Random::uniform(lower, upper),
        Random::uniform(lower, upper)
    );
}

}
}