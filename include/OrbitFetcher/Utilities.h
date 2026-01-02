#pragma once

namespace OrbitFetcher::Utilities
{
    constexpr double relEps { 1e-8 };
    constexpr double absEps { 1e-12 };

    bool approximatelyEqualRel(double a, double b, double relEpsilon);
    bool approximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon);
}
