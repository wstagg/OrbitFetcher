#pragma once
#include "OrbitFetcher/TleParser.h"

struct TleParserFixture
{
    OrbitFetcher::ResponseData::TleData tleData{};
    OrbitFetcher::ResponseData::TleStrings tleString{};
    OrbitFetcher::TleParser tleParser{};

    TleParserFixture()
    {
        tleParser.parseTle("1 25544U 98067A   18077.09047010  .00001878  00000-0  35621-4 0  9999\r\n2 25544  51.6412 112.8495 0001928 208.4187 178.9720 15.54106440104358");
        tleData = tleParser.getTleData();
        tleString = tleParser.getTleStrings();
    }
};