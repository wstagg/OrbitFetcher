#pragma once
#include <string>
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
        static OrbitFetcher::ResponseData::TleLineTwo parseLineTwo(const std::string& lineTwoStr);

        static constexpr std::size_t LINE_ONE_LEN {69};
        static constexpr std::size_t LINE_TWO_LEN {69};
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

    struct TleLineTwoSubStringFields
    {
        SubstringRange lineNumber {0, 1};
        SubstringRange satelliteNumber {2, 5};
        SubstringRange inclinationDegrees{8, 8};
        SubstringRange rightAscensionDegrees {17, 8};
        SubstringRange orbitEccentricity {26, 7};
        SubstringRange argumentOfPerigee {34, 8};
        SubstringRange meanAnomalyDegrees {43, 8};
        SubstringRange meanMotion {52, 11};
        SubstringRange totalRevolutionsAtEpoch {63, 5};
        SubstringRange checksum {68, 1};
    };
}
