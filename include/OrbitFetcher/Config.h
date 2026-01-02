#pragma once
#include <string>

namespace OrbitFetcher
{
    struct ConfigValues
    {
        std::string apiKey{};
        double observerLat{};
        double observerLon{};
        double observerAlt{};
        int searchRadius{};
        int noradId{};
        int searchCategory{};
        int seconds{};
        int days{};
        int minVisibility{};
        int minElevation{};
    };

    class Config
    {
    public:
        Config();
        void read(const std::string& filePath);
        const ConfigValues& getConfigValues();

    private:
        void setConfigValue(const std::string& option, const std::string& value);
        ConfigValues configValues;
    };
}