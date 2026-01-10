#pragma once
#include <curl/curl.h>
#include <memory>
#include <string>
#include <iostream>
#include <optional>

#include "OrbitFetcher/Config.h"
#include "OrbitFetcher/SearchCategory.h"
#include "OrbitFetcher/ApiType.h"
#include "OrbitFetcher/JsonParser.h"

namespace OrbitFetcher
{
    class DataReceiver
    {
    public:
        DataReceiver();
        explicit DataReceiver(Config& _config);
        ~DataReceiver();

        ResponseData::Tle getTle();
        ResponseData::Tle getTle(const std::string& apiKey, const int& noradId);

        ResponseData::SatellitePosition getSatellitePosition();
        ResponseData::SatellitePosition getSatellitePosition(
            const std::string& apiKey,
            const int& noradId,
            const double &observerLat,
            const double &observerLon,
            const double &observerAlt,
            const int& seconds);

        ResponseData::SatelliteVisualPass getSatelliteVisualPass();
        ResponseData::SatelliteVisualPass getSatelliteVisualPass(
            const std::string& apiKey,
            const int& noradId,
            const double &observerLat,
            const double &observerLon,
            const double &observerAlt,
            const int& days,
            const int& minimumVisibility);

        ResponseData::SatelliteRadioPass getSatelliteRadioPass();
        ResponseData::SatelliteRadioPass getSatelliteRadioPass(
            const std::string& apiKey,
            const int& noradId,
            const double &observerLat,
            const double &observerLon,
            const double &observerAlt,
            const int& days,
            const int& minimumElevation);

        ResponseData::SatellitesAbove getSatellitesAbove();
        ResponseData::SatellitesAbove getSatellitesAbove(
            const std::string& apiKey,
            const double &observerLat,
            const double &observerLon,
            const double &observerAlt,
            const int& searchRadius,
            const SearchCategory& searchCategory);

    private:
        struct ApiCallParameters
        {
            std::string apiKey;
            std::optional<int> noradId;
            std::optional<double> observerLat;
            std::optional<double> observerLon;
            std::optional<double> observerAlt;
            std::optional<int> searchRadius;
            std::optional<int> searchCategory;
            std::optional<int> seconds;
            std::optional<int> days;
            std::optional<int> minimumVisibility;
            std::optional<int> minimumElevation;
        };

        struct ApiRequestTemplates
        {
            std::string tle{"https://api.n2yo.com/rest/v1/satellite/tle/{id}/&apiKey="};
            std::string satellitePositions{"https://api.n2yo.com/rest/v1/satellite/positions/{id}/{observer_lat}/{observer_lng}/{observer_alt}/{seconds}/&apiKey="};
            std::string visualPasses{"https://api.n2yo.com/rest/v1/satellite/visualpasses/{id}/{observer_lat}/{observer_lng}/{observer_alt}/{days}/{min_visibility}/&apiKey="};
            std::string radioPasses{"https://api.n2yo.com/rest/v1/satellite/radiopasses/{id}/{observer_lat}/{observer_lng}/{observer_alt}/{days}/{min_elevation}/&apiKey="};
            std::string above{"https://api.n2yo.com/rest/v1/satellite/above/{observer_lat}/{observer_lng}/{observer_alt}/{search_radius}/{category_id}/&apiKey="};
        }apiRequestTemplates;

        template<typename T>
        T callApi(const ApiType apiType, const ApiCallParameters& apiCallParameters);
        std::string createApiUrl(const ApiType apiType, const ApiCallParameters& apiCallParameters);
        int makeCurlRequest(const std::string& apiCallUrl);
        static size_t writeCallback(char *ptr, size_t size, size_t nmemb, void *userdata);
        std::string getApiRequestTemplate(const ApiType apiType);

        std::string dataString{};
        CURL* curl{nullptr};
        Config config;
    };

    template <typename T>
    inline T DataReceiver::callApi(const ApiType apiType, const ApiCallParameters& apiCallParameters)
    {
        if (!dataString.empty())
        {
            dataString.clear();
        }

        const auto apiUrl = createApiUrl(apiType, apiCallParameters);

        const auto res = makeCurlRequest(apiUrl);

        if (res != CURLcode::CURLE_OK)
        {
            throw std::runtime_error("CURL request failed for " + apiUrl + ", error code: " + std::to_string(res));
        }

        if (dataString.empty())
        {
            throw std::runtime_error("Empty response from API: " + apiUrl);
        }

        try
        {
            JsonParser::checkForErrors(dataString);

            T responseData{};
            JsonParser jsonParser;
            jsonParser.parse(dataString, responseData);
            return responseData;
        }
        catch(const std::exception& e)
        {
            throw std::runtime_error( "Failed to parse JSON from api request: " + apiUrl + ". Error:: " + e.what());
        }
    }
}