#include "OrbitFetcher/TleParser.h"
#include <sstream>

OrbitFetcher::ResponseData::TleData OrbitFetcher::TleParser::parseTleString(const std::string& tleString)
{
    const auto endOfLineOnePos = tleString.find_first_of('\r');
    auto lineOne = tleString.substr(0, endOfLineOnePos);
    auto lineTwo = tleString.substr(endOfLineOnePos + 2);

    const auto lineOneData = parseLineOne(lineOne);
    const auto lineTwoData = parseLineTwo(lineTwo);

    return {lineOneData, lineTwoData};
}

OrbitFetcher::ResponseData::TleLineOne OrbitFetcher::TleParser::parseLineOne(const std::string &lineOneStr)
{
    OrbitFetcher::ResponseData::TleLineOne lineOneData{};
    const OrbitFetcher::TleLineOneSubStringFields subStrings;

    lineOneData.lineNumber = std::stoi(lineOneStr.substr(subStrings.lineNumber.start, subStrings.lineNumber.length));
    lineOneData.satelliteNumber = std::stoi(lineOneStr.substr(subStrings.satelliteNumber.start, subStrings.satelliteNumber.length));
    lineOneData.classification = lineOneStr.substr(subStrings.classification.start, subStrings.classification.length).front();
    lineOneData.intlDesignatorLaunchYear = std::stoi(lineOneStr.substr(subStrings.intlDesignatorLaunchYear.start, subStrings.intlDesignatorLaunchYear.length));
    lineOneData.intlDesignatorLaunchNumberOfYear = std::stoi(lineOneStr.substr(subStrings.intlDesignatorLaunchNumber.start, subStrings.intlDesignatorLaunchNumber.length));
    lineOneData.intlDesignatorPieceOfLaunch = lineOneStr.substr(subStrings.intlDesignatorPieceOfLaunch.start, subStrings.intlDesignatorPieceOfLaunch.length);
    lineOneData.epochYear = std::stoi(lineOneStr.substr(subStrings.epochYear.start, subStrings.epochYear.length));
    lineOneData.epochDay = std::stod(lineOneStr.substr(subStrings.epochDay.start, subStrings.epochDay.length));
    lineOneData.firstDerivativeMeanMotion = std::stod(lineOneStr.substr(subStrings.firstDerivativeMeanMotion.start, subStrings.firstDerivativeMeanMotion.length));
    lineOneData.secondDerivativeMeanMotion = std::stod(lineOneStr.substr(subStrings.secondDerivativeMeanMotion.start, subStrings.secondDerivativeMeanMotion.length));
    lineOneData.bStarDragCoefficient = std::stod(lineOneStr.substr(subStrings.bStarDragCoefficient.start, subStrings.bStarDragCoefficient.length));
    lineOneData.ephemerisType = std::stoi(lineOneStr.substr(subStrings.ephemerisType.start, subStrings.ephemerisType.length));
    lineOneData.elementSetNumber = std::stoi(lineOneStr.substr(subStrings.elementSetNumber.start, subStrings.elementSetNumber.length));
    lineOneData.checkSum = std::stoi(lineOneStr.substr(subStrings.checkSum.start, subStrings.checkSum.length));

    return lineOneData;
}

OrbitFetcher::ResponseData::TleLineTwo OrbitFetcher::TleParser::parseLineTwo(std::string &lineTwoStr)
{
    return {};
}

std::vector<std::string> OrbitFetcher::TleParser::splitString(const std::string &str, const char delimiter)
{
    std::istringstream lineOneStream(str);
    std::vector<std::string> elements;
    std::string element;

    while (std::getline(lineOneStream, element, delimiter))
    {
        if (!element.empty())
        {
            elements.push_back(element);
        }
    }

    return elements;
}
