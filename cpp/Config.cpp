#include "OrbitFetcher/Config.h"
#include <fstream>
#include <iostream>

OrbitFetcher::Config::Config()
= default;

void OrbitFetcher::Config::read(const std::string& filePath)
{
    std::fstream f{};

    f.open(filePath, std::ios_base::in);

    if(!f.is_open())
    {
        throw std::runtime_error("Cannot open config.txt file - " + filePath);
    }

    std::string line{};
    
    while (std::getline(f, line))
    {
        if(line.empty())
        {
            continue;
        }
        
        if (line.front() == '#')
        {
            continue;
        }
        
        // remove white space from config line 
       for (auto itt = line.begin() ; itt != line.end() ;)
       {
            if (*itt == ' ')
            {
                itt = line.erase(itt);
            }
            else
            {
                ++itt;
            }
       }

        auto equalPos = line.find_first_of('=');
        auto option = line.substr(0 ,equalPos);
        auto value = line.substr(equalPos + 1);
        setConfigValue(option, value);
    }
}

const OrbitFetcher::ConfigValues &OrbitFetcher::Config::getConfigValues()
{
    return configValues;
}

void OrbitFetcher::Config::setConfigValue(const std::string& option, const std::string& value)
{
    if(option == "API_KEY")
    {
        if (value.empty())
        {
            throw std::invalid_argument("OrbitFetcher::Config::setConfigValue - API_KEY missing value");
        }
        
        configValues.apiKey = value;
    }
    else if(option == "OBSERVER_LAT")
    {
        if (value.empty())
        {
            throw std::invalid_argument("OrbitFetcher::Config::setConfigValue - OBSERVER_LAT missing value");
        }

        double latitude;
        try
        {
            std::size_t pos{};
            latitude = std::stod(value, &pos);

            if (pos != value.length())
            {
                throw std::invalid_argument("OrbitFetcher::Config::setConfigValue - OBSERVER_LAT contains invalid characters: " + value);
            }
        }
        catch (const std::invalid_argument&)
        {
            throw std::invalid_argument("OrbitFetcher::Config::setConfigValue - OBSERVER_LAT invalid format: " + value);
        }

        if (latitude < -90.0 || latitude > 90.0)
        {
            throw std::out_of_range("OrbitFetcher::Config::setConfigValue - OBSERVER_LAT must be between -90 and 90 degrees");
        }

        configValues.observerLat = latitude;
    }
    else if(option == "OBSERVER_LON")
    {
        if (value.empty())
        {
            throw std::invalid_argument("OrbitFetcher::Config::setConfigValue - OBSERVER_LON missing value");
        }

        double longitude;
        try
        {
            std::size_t pos{};
            longitude = std::stod(value, &pos);

            if (pos != value.length())
            {
                throw std::invalid_argument("OrbitFetcher::Config::setConfigValue - OBSERVER_LON contains invalid characters: " + value);
            }
        }
        catch (const std::invalid_argument&)
        {
            throw std::invalid_argument("OrbitFetcher::Config::setConfigValue - OBSERVER_LON invalid format: " + value);
        }

        if (longitude < -180.0 || longitude > 180.0)
        {
            throw std::out_of_range("OrbitFetcher::Config::setConfigValue - OBSERVER_LON must be between -180 and 180 degrees");
        }

        configValues.observerLon = longitude;
    }
    else if(option == "OBSERVER_ALT")
    {
        if (value.empty())
        {
            throw std::invalid_argument("OrbitFetcher::Config::setConfigValue - OBSERVER_ALT missing value");
        }

        double altitude;
        try
        {
            std::size_t pos{};
            altitude = std::stod(value, &pos);

            if (pos != value.length())
            {
                throw std::invalid_argument("OrbitFetcher::Config::setConfigValue - OBSERVER_ALT contains invalid characters: " + value);
            }
        }
        catch (const std::invalid_argument&)
        {
            throw std::invalid_argument("OrbitFetcher::Config::setConfigValue - OBSERVER_ALT invalid format: " + value);
        }

        configValues.observerAlt = altitude;
    }
    else if(option == "SEARCH_RAD")
    {
        if (value.empty())
        {
            throw std::invalid_argument("OrbitFetcher::Config::setConfigValue - SEARCH_RAD missing value");
        }

        int searchRadius;
        try
        {
            std::size_t pos{};
            searchRadius = std::stoi(value, &pos);

            if (pos != value.length())
            {
                throw std::invalid_argument("OrbitFetcher::Config::setConfigValue - SEARCH_RAD contains invalid characters: " + value);
            }
        }
        catch (const std::invalid_argument&)
        {
            throw std::invalid_argument("OrbitFetcher::Config::setConfigValue - SEARCH_RAD invalid format: " + value);
        }

        if (searchRadius < 0 || searchRadius > 90)
        {
            throw std::out_of_range("OrbitFetcher::Config::setConfigValue - SEARCH_RAD must be between 0 and 90 degrees");
        }

        configValues.searchRadius = searchRadius;
    }
    else if(option == "NORAD_ID")
    {
        if (value.empty())
        {
            throw std::invalid_argument("OrbitFetcher::Config::setConfigValue - NORAD_ID missing value");
        }

        int noradID;
        try
        {
            std::size_t pos{};
            noradID = std::stoi(value, &pos);

            if (pos != value.length())
            {
                throw std::invalid_argument("OrbitFetcher::Config::setConfigValue - NORAD_ID contains invalid characters: " + value);
            }
        }
        catch (const std::invalid_argument&)
        {
            throw std::invalid_argument("OrbitFetcher::Config::setConfigValue - NORAD_ID invalid format: " + value);
        }

        if (noradID <= 0)
        {
            throw std::invalid_argument("OrbitFetcher::Config::setConfigValue - NORAD_ID needs to be a valid ID");
        }

        configValues.noradId = noradID;
    }
    else if(option == "SEARCH_CATEGORY")
    {
        if (value.empty())
        {
            throw std::invalid_argument("OrbitFetcher::Config::setConfigValue - SEARCH_CATEGORY missing value");
        }

        int searchCategory;
        try
        {
            std::size_t pos{};
            searchCategory = std::stoi(value, &pos);

            if (pos != value.length())
            {
                throw std::invalid_argument("OrbitFetcher::Config::setConfigValue - SEARCH_CATEGORY contains invalid characters: " + value);
            }
        }
        catch (const std::invalid_argument&)
        {
            throw std::invalid_argument("OrbitFetcher::Config::setConfigValue - SEARCH_CATEGORY invalid format: " + value);
        }

        if (searchCategory < 0 || searchCategory > 57)
        {
            throw std::out_of_range("OrbitFetcher::Config::setConfigValue - SEARCH_CATEGORY must be between 0 and 57");
        }

        configValues.searchCategory = searchCategory;
    }
    else if(option == "SECONDS")
    {
        if (value.empty())
        {
            throw std::invalid_argument("OrbitFetcher::Config::setConfigValue - SECONDS missing value");
        }

        int seconds;
        try
        {
            std::size_t pos{};
            seconds = std::stoi(value, &pos);

            if (pos != value.length())
            {
                throw std::invalid_argument("OrbitFetcher::Config::setConfigValue - SECONDS contains invalid characters: " + value);
            }
        }
        catch (const std::invalid_argument&)
        {
            throw std::invalid_argument("OrbitFetcher::Config::setConfigValue - SECONDS invalid format: " + value);
        }

        if (seconds <= 0 || seconds > 300)
        {
            throw std::out_of_range("OrbitFetcher::Config::setConfigValue - SECONDS must be between 0 and 300");
        }

        configValues.seconds = seconds;
    }
    else if(option == "DAYS")
    {
        if (value.empty())
        {
            throw std::invalid_argument("OrbitFetcher::Config::setConfigValue - DAYS missing value");
        }

        int days;
        try
        {
            std::size_t pos{};
            days = std::stoi(value, &pos);

            if (pos != value.length())
            {
                throw std::invalid_argument("OrbitFetcher::Config::setConfigValue - DAYS contains invalid characters: " + value);
            }
        }
        catch (const std::invalid_argument&)
        {
            throw std::invalid_argument("OrbitFetcher::Config::setConfigValue - DAYS invalid format: " + value);
        }

        if (days <= 0 || days > 10)
        {
            throw std::out_of_range("OrbitFetcher::Config::setConfigValue - DAYS must be between 0 and 10");
        }

        configValues.days = days;
    }
    else if(option == "MIN_VISIBILITY")
    {
        if (value.empty())
        {
            throw std::invalid_argument("OrbitFetcher::Config::setConfigValue - MIN_VISIBILITY missing value");
        }

        int minVisibility;
        try
        {
            std::size_t pos{};
            minVisibility = std::stoi(value, &pos);

            if (pos != value.length())
            {
                throw std::invalid_argument("OrbitFetcher::Config::setConfigValue - MIN_VISIBILITY contains invalid characters: " + value);
            }
        }
        catch (const std::invalid_argument&)
        {
            throw std::invalid_argument("OrbitFetcher::Config::setConfigValue - MIN_VISIBILITY invalid format: " + value);
        }

        if (minVisibility <= 0)
        {
            throw std::invalid_argument("OrbitFetcher::Config::setConfigValue - MIN_VISIBILITY must be greater than zero");
        }

        configValues.minVisibility = minVisibility;
    }
    else if(option == "MIN_ELEVATION")
    {
        if (value.empty())
        {
            throw std::invalid_argument("OrbitFetcher::Config::setConfigValue - MIN_ELEVATION missing value");
        }

        int minElevation;
        try
        {
            std::size_t pos{};
            minElevation = std::stoi(value, &pos);

            if (pos != value.length())
            {
                throw std::invalid_argument("OrbitFetcher::Config::setConfigValue - MIN_ELEVATION contains invalid characters: " + value);
            }
        }
        catch (const std::invalid_argument&)
        {
            throw std::invalid_argument("OrbitFetcher::Config::setConfigValue - MIN_ELEVATION invalid format: " + value);
        }

        if (minElevation <= 0 || minElevation > 360)
        {
            throw std::out_of_range("OrbitFetcher::Config::setConfigValue - MIN_ELEVATION must be between 0 and 360");
        }

        configValues.minElevation = minElevation;
    }
}