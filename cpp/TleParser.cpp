#include "OrbitFetcher/TleParser.h"

#include <cmath>
#include <string>
#include <stdexcept>

OrbitFetcher::ResponseData::TleData OrbitFetcher::TleParser::parseTleString(const std::string& tleString, std::string& inLineOne, std::string& inLineTwo)
{
    const auto endOfLineOnePos = tleString.find_first_of('\r');
    auto lineOne = tleString.substr(0, endOfLineOnePos);
    auto lineTwo = tleString.substr(endOfLineOnePos + 2);

    // set tle.strings one and two
    inLineOne = lineOne;
    inLineTwo = lineTwo;

    const auto lineOneData = parseLineOne(lineOne);
    const auto lineTwoData = parseLineTwo(lineTwo);

    return {lineOneData, lineTwoData};
}

OrbitFetcher::ResponseData::TleLineOne OrbitFetcher::TleParser::parseLineOne(const std::string &lineOneStr)
{
    OrbitFetcher::ResponseData::TleLineOne lineOneData{};

    if (lineOneStr.length() < LINE_ONE_LEN)
    {
        throw std::runtime_error("OrbitFetcher::TleParser::parseLineOne - lineOneStr len < LINE_ONE_LEN");
    }
    if (lineOneStr.length() > LINE_ONE_LEN)
    {
        throw std::runtime_error("OrbitFetcher::TleParser::parseLineOne - lineOneStr len > LINE_ONE_LEN");
    }

    constexpr OrbitFetcher::TleLineOneSubStringFields subStrings;

    lineOneData.lineNumber = std::stoi(lineOneStr.substr(subStrings.lineNumber.start, subStrings.lineNumber.length));
    lineOneData.satelliteNumber = std::stoi(lineOneStr.substr(subStrings.satelliteNumber.start, subStrings.satelliteNumber.length));
    lineOneData.classification = lineOneStr.substr(subStrings.classification.start, subStrings.classification.length).front();
    lineOneData.intlDesignatorLaunchYear = std::stoi(lineOneStr.substr(subStrings.intlDesignatorLaunchYear.start, subStrings.intlDesignatorLaunchYear.length));
    lineOneData.intlDesignatorLaunchNumberOfYear = std::stoi(lineOneStr.substr(subStrings.intlDesignatorLaunchNumber.start, subStrings.intlDesignatorLaunchNumber.length));
    lineOneData.intlDesignatorPieceOfLaunch = lineOneStr.substr(subStrings.intlDesignatorPieceOfLaunch.start, subStrings.intlDesignatorPieceOfLaunch.length);
    lineOneData.epochYear = std::stoi(lineOneStr.substr(subStrings.epochYear.start, subStrings.epochYear.length));
    lineOneData.epochDay = std::stod(lineOneStr.substr(subStrings.epochDay.start, subStrings.epochDay.length));
    lineOneData.firstDerivativeMeanMotion = std::stod(lineOneStr.substr(subStrings.firstDerivativeMeanMotion.start, subStrings.firstDerivativeMeanMotion.length));
    lineOneData.secondDerivativeMeanMotion = parseTleExponentialField(lineOneStr.substr(subStrings.secondDerivativeMeanMotion.start, subStrings.secondDerivativeMeanMotion.length));
    lineOneData.bStarDragCoefficient = parseTleExponentialField(lineOneStr.substr(subStrings.bStarDragCoefficient.start, subStrings.bStarDragCoefficient.length));
    lineOneData.ephemerisType = std::stoi(lineOneStr.substr(subStrings.ephemerisType.start, subStrings.ephemerisType.length));
    lineOneData.elementSetNumber = std::stoi(lineOneStr.substr(subStrings.elementSetNumber.start, subStrings.elementSetNumber.length));
    lineOneData.checkSum = std::stoi(lineOneStr.substr(subStrings.checkSum.start, subStrings.checkSum.length));

    return lineOneData;
}

OrbitFetcher::ResponseData::TleLineTwo OrbitFetcher::TleParser::parseLineTwo(const std::string &lineTwoStr)
{
    OrbitFetcher::ResponseData::TleLineTwo lineTwoData{};

    if (lineTwoStr.length() < LINE_TWO_LEN)
    {
        throw std::runtime_error("OrbitFetcher::TleParser::parseLineTwo - lineTwoStr.length() < LINE_TWO_LEN");
    }
    if (lineTwoStr.length() > LINE_TWO_LEN)
    {
        throw std::runtime_error("OrbitFetcher::TleParser::parseLineTwo - lineTwoStr.length() > LINE_TWO_LEN");
    }

    constexpr OrbitFetcher::TleLineTwoSubStringFields subStrings;

    lineTwoData.lineNumber = std::stoi(lineTwoStr.substr(subStrings.lineNumber.start, subStrings.lineNumber.length));
    lineTwoData.satelliteNumber = std::stoi(lineTwoStr.substr(subStrings.satelliteNumber.start, subStrings.satelliteNumber.length));
    lineTwoData.inclinationDegrees = std::stod(lineTwoStr.substr(subStrings.inclinationDegrees.start, subStrings.inclinationDegrees.length));
    lineTwoData.rightAscensionDegrees = std::stod(lineTwoStr.substr(subStrings.rightAscensionDegrees.start, subStrings.rightAscensionDegrees.length));
    lineTwoData.orbitEccentricity = std::stod("0." + lineTwoStr.substr(subStrings.orbitEccentricity.start, subStrings.orbitEccentricity.length));
    lineTwoData.argumentOfPerigee = std::stod(lineTwoStr.substr(subStrings.argumentOfPerigee.start, subStrings.argumentOfPerigee.length));
    lineTwoData.meanAnomalyDegrees = std::stod(lineTwoStr.substr(subStrings.meanAnomalyDegrees.start, subStrings.meanAnomalyDegrees.length));
    lineTwoData.meanMotion = std::stod(lineTwoStr.substr(subStrings.meanMotion.start, subStrings.meanMotion.length));
    lineTwoData.totalRevolutionsAtEpoch = std::stoi(lineTwoStr.substr(subStrings.totalRevolutionsAtEpoch.start, subStrings.totalRevolutionsAtEpoch.length));
    lineTwoData.checkSum = std::stoi(lineTwoStr.substr(subStrings.checksum.start, subStrings.checksum.length));

    return lineTwoData;
}

double OrbitFetcher::TleParser::parseTleExponentialField(const std::string &field)
{
    size_t startPos {0};
    double mantissaSign {1.0};
    int exponent {1};

    // Check for leading sign
    if (field[0] == '-')
    {
        mantissaSign = -1.0;
        startPos = 1;
    }

    // find position of exponent
    const size_t expPos = field.find_first_of('-', startPos);

    if (expPos != std::string::npos)
    {
        // Extract exponent
        const std::string exponentStr = field.substr(expPos);
        exponent = std::stoi(exponentStr);
    }

    // Extract mantissa digits (between start and exponent)
    const std::string mantissaStr = expPos == std::string::npos ? field.substr(startPos) : field.substr(startPos, expPos - startPos);
    const auto d = std::stod(mantissaStr);

    std::string zero = {"0."};
    zero.append(std::to_string(d));

    const double mantissa = std::stod(zero) * mantissaSign;

    return mantissa * (std::pow(10.0, exponent));
}
