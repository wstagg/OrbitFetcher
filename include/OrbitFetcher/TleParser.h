#pragma once
#include <string>
#include <vector>
#include "ResponseData.h"

namespace OrbitFetcher
{
    class TleParser
    {
    public:
        TleParser() = default;
        static ResponseData::TleData parseTleString(const std::string& tleString);

    private:
        static OrbitFetcher::ResponseData::TleLineOne parseLineOne(const std::string& lineOneStr);
        static OrbitFetcher::ResponseData::TleLineTwo parseLineTwo(std::string& lineTwoStr);
        static std::vector<std::string> splitString(const std::string& str, const char delimiter);
    };

    struct SubstringRange
    {
        std::size_t start;
        std::size_t length;
    };

    struct TleLineOneSubStringFields
    {
        SubstringRange lineNumber {0, 1};
        SubstringRange satelliteNumber {2, 5};
        SubstringRange classification {7, 1};
        SubstringRange intlDesignatorLaunchYear {9, 2};
        SubstringRange intlDesignatorLaunchNumber {11, 3};
        SubstringRange intlDesignatorPieceOfLaunch {14, 3};
        SubstringRange epochYear {18, 2};
        SubstringRange epochDay {20, 12};
        SubstringRange firstDerivativeMeanMotion {33, 10};
        SubstringRange secondDerivativeMeanMotion {44, 8};
        SubstringRange bStarDragCoefficient {53, 8};
        SubstringRange ephemerisType {62, 1};
        SubstringRange elementSetNumber {64, 4};
        SubstringRange checkSum {68, 1};
    };
}
