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
    
double Random::uniform() {
    return Random::uniform(0.0, 1.0);
}

double Random::uniform(double lower, double upper) {
    std::uniform_real_distribution<double> dist(lower, upper);
    return dist(Random::rng);
}

}
}