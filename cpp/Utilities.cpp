#include "OrbitFetcher/Utilities.h"
#include <algorithm>
#include <cmath>

bool OrbitFetcher::Utilities::approximatelyEqualRel(const double a, const double b, const double relEpsilon)
{
    return (std::abs(a - b) <= (std::max(std::abs(a), std::abs(b)) * relEpsilon));
}

bool OrbitFetcher::Utilities::approximatelyEqualAbsRel(const double a, const double b, const double absEpsilon, const double relEpsilon)
{
    if (std::abs(a - b) <= absEpsilon)
    {
        return true;
    }

    // Otherwise fall back to Knuth's algorithm
    return approximatelyEqualRel(a, b, relEpsilon);
}
