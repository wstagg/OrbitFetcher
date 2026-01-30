#pragma once
#include "OrbitFetcher/ResponseData.h"
#include "ApiType.h"
#include <variant>

namespace OrbitFetcher
{
    class JsonParser
    {
    public:
        JsonParser() = default;
        template<typename T>
        void parse(const std::string_view& dataString, T& responseData);
        static void checkForResponseErrors(const std::string_view& dataString);
    private:
        static void parseTle(const std::string_view& dataString, ResponseData::Tle& tle);
        static void parseSatellitePositions(const std::string_view& dataString, ResponseData::SatellitePosition& satellitePosition);
        static void parseVisualPass(const std::string_view& dataString, ResponseData::SatelliteVisualPass& satelliteVisualPass);
        static void parseRadioPass(const std::string_view& dataString, ResponseData::SatelliteRadioPass& satelliteRadioPass);
        static void parseWhatsAbove(const std::string_view& dataString, ResponseData::SatellitesAbove& satellitesAbove);
    };

    template <typename T>
    inline void JsonParser::parse(const std::string_view& dataString, T& responseData)
    {
        if constexpr(std::is_same_v<T, ResponseData::Tle>)
        {
            parseTle(dataString, responseData);
        }
        else if constexpr(std::is_same_v<T, ResponseData::SatellitePosition>)
        {
            parseSatellitePositions(dataString, responseData);
        }
        else if constexpr(std::is_same_v<T, ResponseData::SatelliteVisualPass>)
        {
            parseVisualPass(dataString, responseData);
        }
        else if constexpr(std::is_same_v<T, ResponseData::SatelliteRadioPass>)
        {
            parseRadioPass(dataString, responseData);
        }
        else if constexpr(std::is_same_v<T, ResponseData::SatellitesAbove>)
        {
            parseWhatsAbove(dataString, responseData);
        }
    }
}