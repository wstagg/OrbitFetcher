#pragma once
#include <string>
#include <vector>
#include "OrbitFetcher/Utilities.h"

namespace OrbitFetcher::ResponseData
{
    struct TleLineOne
    {
        int lineNumber;
        int satelliteNumber;
        char classification;
        int intlDesignatorLaunchYear;
        int intlDesignatorLaunchNumberOfYear;
        std::string intlDesignatorPieceOfLaunch;
        int epochYear;
        double epochDay;
        double firstDerivativeMeanMotion;
        double secondDerivativeMeanMotion;
        double bStarDragCoefficient;
        int ephemerisType;
        int elementSetNumber;
        int checkSum;
    };

    struct TleLineTwo
    {
        int lineNumber;
        int satelliteNumber;
        double inclinationDegrees;
        double rightAscensionDegrees;
        double orbitEccentricity;
        double argumentOfPerigee;
        double meanAnomalyDegrees;
        double meanMotion; //revolutions per day
        int totalRevolutionsAtEpoch;
        int checkSum;
    };

    struct TleData
    {
        TleLineOne tleLineOne;
        TleLineTwo tleLineTwo;
    };

    struct TleStrings
    {
        std::string lineOne;
        std::string lineTwo;
        std::string complete;
    };

    struct Tle
    {
        int satId;
        std::string satName;
        int transactionCount;
        TleStrings tleStrings;
        TleData tleData;
    };

    struct PositionData
    {
        double lat;
        double lon;
        double altKm;
        double azimuth;
        double elevation;
        double rightAscension;
        double declination;
        int timeStamp;

        bool operator == (const PositionData& positionData2) const
        {
            return (OrbitFetcher::Utilities::approximatelyEqualAbsRel(this->lat, positionData2.lat, OrbitFetcher::Utilities::absEps, OrbitFetcher::Utilities::relEps) &&
                    OrbitFetcher::Utilities::approximatelyEqualAbsRel(this->lon, positionData2.lon, OrbitFetcher::Utilities::absEps, OrbitFetcher::Utilities::relEps) &&
                    OrbitFetcher::Utilities::approximatelyEqualAbsRel(this->altKm, positionData2.altKm, OrbitFetcher::Utilities::absEps, OrbitFetcher::Utilities::relEps) &&
                    OrbitFetcher::Utilities::approximatelyEqualAbsRel(this->azimuth, positionData2.azimuth, OrbitFetcher::Utilities::absEps, OrbitFetcher::Utilities::relEps) &&
                    OrbitFetcher::Utilities::approximatelyEqualAbsRel(this->elevation, positionData2.elevation, OrbitFetcher::Utilities::absEps, OrbitFetcher::Utilities::relEps) &&
                    OrbitFetcher::Utilities::approximatelyEqualAbsRel(this->rightAscension, positionData2.rightAscension, OrbitFetcher::Utilities::absEps, OrbitFetcher::Utilities::relEps) &&
                    OrbitFetcher::Utilities::approximatelyEqualAbsRel(this->declination, positionData2.declination, OrbitFetcher::Utilities::absEps, OrbitFetcher::Utilities::relEps) &&
                    this->timeStamp == positionData2.timeStamp);
        }
    };

    struct SatellitePosition
    {
        int satId;
        std::string satName;
        int transactionCount;
        std::vector<PositionData> positionData;
    };

    struct VisualPassData
    {
        double startAzimuth;
        std::string startAzimuthCompass;
        double startElevation;
        int startUTC;
        double maxAzimuth;
        std::string maxAzimuthCompass;
        double maxElevation;
        int maxUTC;
        double endAzimuth;
        std::string endAzimuthCompass;
        double endElevation;
        int endUTC;
        double maxVisualMagnitude;
        int visibleDuration;

        bool operator == (const VisualPassData& visualPassData2) const
        {
            return (OrbitFetcher::Utilities::approximatelyEqualAbsRel(this->startAzimuth, visualPassData2.startAzimuth, OrbitFetcher::Utilities::absEps, OrbitFetcher::Utilities::relEps) &&
                    this->startAzimuthCompass == visualPassData2.startAzimuthCompass &&
                    OrbitFetcher::Utilities::approximatelyEqualAbsRel(this->startElevation, visualPassData2.startElevation, OrbitFetcher::Utilities::absEps, OrbitFetcher::Utilities::relEps)  &&
                    this->startUTC == visualPassData2.startUTC &&
                    OrbitFetcher::Utilities::approximatelyEqualAbsRel(this->maxAzimuth, visualPassData2.maxAzimuth, OrbitFetcher::Utilities::absEps, OrbitFetcher::Utilities::relEps)  &&
                    this->maxAzimuthCompass == visualPassData2.maxAzimuthCompass &&
                    OrbitFetcher::Utilities::approximatelyEqualAbsRel(this->maxElevation, visualPassData2.maxElevation, OrbitFetcher::Utilities::absEps, OrbitFetcher::Utilities::relEps)  &&
                    this->maxUTC == visualPassData2.maxUTC &&
                    OrbitFetcher::Utilities::approximatelyEqualAbsRel(this->endAzimuth, visualPassData2.endAzimuth, OrbitFetcher::Utilities::absEps, OrbitFetcher::Utilities::relEps)  &&
                    this->endAzimuthCompass == visualPassData2.endAzimuthCompass &&
                    OrbitFetcher::Utilities::approximatelyEqualAbsRel(this->endElevation, visualPassData2.endElevation, OrbitFetcher::Utilities::absEps, OrbitFetcher::Utilities::relEps)  &&
                    this->endUTC == visualPassData2.endUTC &&
                    OrbitFetcher::Utilities::approximatelyEqualAbsRel(this->maxVisualMagnitude, visualPassData2.maxVisualMagnitude, OrbitFetcher::Utilities::absEps, OrbitFetcher::Utilities::relEps)  &&
                    this->visibleDuration == visualPassData2.visibleDuration
            );
        }
    };

    struct SatelliteVisualPass
    {
        int satId;
        std::string satName;
        int transactionCount;
        int passCount;
        std::vector<VisualPassData> visualPassData;
    };

    struct RadioPassData
    {
        double startAzimuth;
        std::string startAzimuthCompass;
        int startUTC;
        double maxAzimuth;
        std::string maxAzimuthCompass;
        double maxElevation;
        int maxUTC;
        double endAzimuth;
        std::string endAzimuthCompass;
        int endUTC;

        bool operator == (const RadioPassData& RadioPassData2) const
        {
            return (OrbitFetcher::Utilities::approximatelyEqualAbsRel(this->startAzimuth, RadioPassData2.startAzimuth, OrbitFetcher::Utilities::absEps, OrbitFetcher::Utilities::relEps)  &&
                    this->startAzimuthCompass == RadioPassData2.startAzimuthCompass &&
                    this->startUTC == RadioPassData2.startUTC &&
                    OrbitFetcher::Utilities::approximatelyEqualAbsRel(this->maxAzimuth, RadioPassData2.maxAzimuth, OrbitFetcher::Utilities::absEps, OrbitFetcher::Utilities::relEps) &&
                    this->maxAzimuthCompass == RadioPassData2.maxAzimuthCompass &&
                    OrbitFetcher::Utilities::approximatelyEqualAbsRel(this->maxElevation, RadioPassData2.maxElevation, OrbitFetcher::Utilities::absEps, OrbitFetcher::Utilities::relEps) &&
                    this->maxUTC == RadioPassData2.maxUTC &&
                    OrbitFetcher::Utilities::approximatelyEqualAbsRel(this->endAzimuth, RadioPassData2.endAzimuth, OrbitFetcher::Utilities::absEps, OrbitFetcher::Utilities::relEps) &&
                    this->endAzimuthCompass == RadioPassData2.endAzimuthCompass &&
                    this->endUTC == RadioPassData2.endUTC);
        }
    };

    struct SatelliteRadioPass
    {
        int satId;
        std::string satName;
        int transactionCount;
        int passCount;
        std::vector<RadioPassData> radioPassData;
    };

    struct SatelliteData
    {
        int satId;
        std::string satName;
        std::string internationalDesignator;
        std::string launchDate;
        double lat;
        double lon;
        double altKm;

        bool operator == (const SatelliteData& satelliteData2) const
        {
            return (this->satId == satelliteData2.satId &&
                    this->satName == satelliteData2.satName &&
                    this->internationalDesignator == satelliteData2.internationalDesignator &&
                    this->launchDate == satelliteData2.launchDate &&
                    OrbitFetcher::Utilities::approximatelyEqualAbsRel(this->lat, satelliteData2.lat, OrbitFetcher::Utilities::absEps, OrbitFetcher::Utilities::relEps) &&
                    OrbitFetcher::Utilities::approximatelyEqualAbsRel(this->lon, satelliteData2.lon, OrbitFetcher::Utilities::absEps, OrbitFetcher::Utilities::relEps) &&
                    OrbitFetcher::Utilities::approximatelyEqualAbsRel(this->altKm, satelliteData2.altKm, OrbitFetcher::Utilities::absEps, OrbitFetcher::Utilities::relEps));
        }
    };

    struct SatellitesAbove
    {
        std::string category;
        int transactionCount;
        int satelliteCount;
        std::vector<SatelliteData> satellitesAbove;
    };
}
