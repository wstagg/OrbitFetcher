#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>
#include <boost/python/reference_existing_object.hpp>
#include <boost/python/return_value_policy.hpp>

#include "OrbitFetcher/Config.h"
#include "OrbitFetcher/DataReceiver.h"
#include "OrbitFetcher/ResponseData.h"
#include "OrbitFetcher/SearchCategory.h"


BOOST_PYTHON_MODULE(OrbitFetcher)
{
    // Search category
    boost::python::enum_<OrbitFetcher::SearchCategory>("OrbitFetcher::SearchCategory")
    .value("All", OrbitFetcher::SearchCategory::All)
    .value("Brightest", OrbitFetcher::SearchCategory::Brightest)
    .value("ISS", OrbitFetcher::SearchCategory::ISS)
    .value("Weather", OrbitFetcher::SearchCategory::Weather)
    .value("NOAA", OrbitFetcher::SearchCategory::NOAA)
    .value("GOES", OrbitFetcher::SearchCategory::GOES)
    .value("EarthResources", OrbitFetcher::SearchCategory::EarthResources)
    .value("SearchAndRescue", OrbitFetcher::SearchCategory::SearchAndRescue)
    .value("DisasterMonitoring", OrbitFetcher::SearchCategory::DisasterMonitoring)
    .value("TrackingAndDataRelaySatelliteSystem", OrbitFetcher::SearchCategory::TrackingAndDataRelaySatelliteSystem)
    .value("Geostationary", OrbitFetcher::SearchCategory::Geostationary)
    .value("Intelsat", OrbitFetcher::SearchCategory::Intelsat)
    .value("Gorizont", OrbitFetcher::SearchCategory::Gorizont)
    .value("Raduga", OrbitFetcher::SearchCategory::Raduga)
    .value("Molniya", OrbitFetcher::SearchCategory::Molniya)
    .value("Iridium", OrbitFetcher::SearchCategory::Iridium)
    .value("Orbcomm", OrbitFetcher::SearchCategory::Orbcomm)
    .value("Globalstar", OrbitFetcher::SearchCategory::Globalstar)
    .value("AmateurRadio", OrbitFetcher::SearchCategory::AmateurRadio)
    .value("Experimental", OrbitFetcher::SearchCategory::Experimental)
    .value("GPSOperational", OrbitFetcher::SearchCategory::GPSOperational)
    .value("GlonassOperational", OrbitFetcher::SearchCategory::GlonassOperational)
    .value("Galileo", OrbitFetcher::SearchCategory::Galileo)
    .value("SatelliteBasedAugmentationSystem", OrbitFetcher::SearchCategory::SatelliteBasedAugmentationSystem)
    .value("NavyNavigationSatelliteSystem", OrbitFetcher::SearchCategory::NavyNavigationSatelliteSystem)
    .value("RussianLEONavigation", OrbitFetcher::SearchCategory::RussianLEONavigation)
    .value("SpaceAndEarthScience", OrbitFetcher::SearchCategory::SpaceAndEarthScience)
    .value("Geodetic", OrbitFetcher::SearchCategory::Geodetic)
    .value("Engineering", OrbitFetcher::SearchCategory::Engineering)
    .value("Education", OrbitFetcher::SearchCategory::Education)
    .value("Military", OrbitFetcher::SearchCategory::Military)
    .value("RadarCalibration", OrbitFetcher::SearchCategory::RadarCalibration)
    .value("CubeSats", OrbitFetcher::SearchCategory::CubeSats)
    .value("XMandSirius", OrbitFetcher::SearchCategory::XMandSirius)
    .value("TV", OrbitFetcher::SearchCategory::TV)
    .value("BeidouNavigationSystem", OrbitFetcher::SearchCategory::BeidouNavigationSystem)
    .value("Yaogan", OrbitFetcher::SearchCategory::Yaogan)
    .value("WestfordNeedles", OrbitFetcher::SearchCategory::WestfordNeedles)
    .value("Parus", OrbitFetcher::SearchCategory::Parus)
    .value("Strela", OrbitFetcher::SearchCategory::Strela)
    .value("Gonets", OrbitFetcher::SearchCategory::Gonets)
    .value("Tsiklon", OrbitFetcher::SearchCategory::Tsiklon)
    .value("Tsikada", OrbitFetcher::SearchCategory::Tsikada)
    .value("O3BNetworks", OrbitFetcher::SearchCategory::O3BNetworks)
    .value("Tselina", OrbitFetcher::SearchCategory::Tselina)
    .value("Celestis", OrbitFetcher::SearchCategory::Celestis)
    .value("IRNSS", OrbitFetcher::SearchCategory::IRNSS)
    .value("QZSS", OrbitFetcher::SearchCategory::QZSS)
    .value("Flock", OrbitFetcher::SearchCategory::Flock)
    .value("Lemur", OrbitFetcher::SearchCategory::Lemur)
    .value("GPSConstellation", OrbitFetcher::SearchCategory::GPSConstellation)
    .value("GlonassConstellation", OrbitFetcher::SearchCategory::GlonassConstellation)
    .value("Starlink", OrbitFetcher::SearchCategory::Starlink)
    .value("OneWeb", OrbitFetcher::SearchCategory::OneWeb)
    .value("ChineseSpaceStation", OrbitFetcher::SearchCategory::ChineseSpaceStation)
    .value("Qianfan", OrbitFetcher::SearchCategory::Qianfan)
    .value("Kuiper", OrbitFetcher::SearchCategory::Kuiper);

    // Config
    boost::python::class_<OrbitFetcher::ConfigValues>("ConfigValues")
        .def_readonly("apiKey", &OrbitFetcher::ConfigValues::apiKey)
        .def_readonly("observerLat", &OrbitFetcher::ConfigValues::observerLat)
        .def_readonly("observerLon", &OrbitFetcher::ConfigValues::observerLon)
        .def_readonly("observerAlt", &OrbitFetcher::ConfigValues::observerAlt)
        .def_readonly("searchRadius", &OrbitFetcher::ConfigValues::searchRadius)
        .def_readonly("seconds", &OrbitFetcher::ConfigValues::seconds)
        .def_readonly("days", &OrbitFetcher::ConfigValues::days)
        .def_readonly("minVisibility", &OrbitFetcher::ConfigValues::minVisibility)
        .def_readonly("minElevation", &OrbitFetcher::ConfigValues::minElevation)
        .def_readonly("searchCategory", &OrbitFetcher::ConfigValues::searchCategory);

    boost::python::class_<OrbitFetcher::Config>("Config", boost::python::init<>())
        .def("read", &OrbitFetcher::Config::read)
        .def("getConfigValues", &OrbitFetcher::Config::getConfigValues, boost::python::return_value_policy<boost::python::reference_existing_object>());

    // DataReceiver function overloads
    OrbitFetcher::ResponseData::Tle (OrbitFetcher::DataReceiver::*getTleNoArgs)() = &OrbitFetcher::DataReceiver::getTle;
    OrbitFetcher::ResponseData::Tle (OrbitFetcher::DataReceiver::*getTleWithArgs)(const std::string&, const int&) = &OrbitFetcher::DataReceiver::getTle;

    OrbitFetcher::ResponseData::SatellitePosition (OrbitFetcher::DataReceiver::*getSatellitePositionNoArgs)() = &OrbitFetcher::DataReceiver::getSatellitePosition;
    OrbitFetcher::ResponseData::SatellitePosition (OrbitFetcher::DataReceiver::*getSatellitePositionWithArgs)(
        const std::string&,
        const int&,
        const double&,
        const double&,
        const double&,
        const int&) = &OrbitFetcher::DataReceiver::getSatellitePosition;

    OrbitFetcher::ResponseData::SatelliteVisualPass (OrbitFetcher::DataReceiver::*getSatelliteVisualPassNoArgs)() = &OrbitFetcher::DataReceiver::getSatelliteVisualPass;
    OrbitFetcher::ResponseData::SatelliteVisualPass (OrbitFetcher::DataReceiver::*getSatelliteVisualWithArgs)(
        const std::string&,
        const int&,
        const double&,
        const double&,
        const double&,
        const int&,
        const int&) = &OrbitFetcher::DataReceiver::getSatelliteVisualPass;

    OrbitFetcher::ResponseData::SatelliteRadioPass (OrbitFetcher::DataReceiver::*getSatelliteRadioPassNoArgs)() = &OrbitFetcher::DataReceiver::getSatelliteRadioPass;
    OrbitFetcher::ResponseData::SatelliteRadioPass (OrbitFetcher::DataReceiver::*getSatelliteRadioWithArgs)(
        const std::string&,
        const int&,
        const double&,
        const double&,
        const double&,
        const int&,
        const int&) = &OrbitFetcher::DataReceiver::getSatelliteRadioPass;

    OrbitFetcher::ResponseData::SatellitesAbove (OrbitFetcher::DataReceiver::*getSatellitesAboveNoArgs)() = &OrbitFetcher::DataReceiver::getSatellitesAbove;
    OrbitFetcher::ResponseData::SatellitesAbove (OrbitFetcher::DataReceiver::*getSatellitesAboveWithArgs)(
        const std::string&,
        const double&,
        const double&,
        const double&,
        const int&,
        const OrbitFetcher::SearchCategory&) = &OrbitFetcher::DataReceiver::getSatellitesAbove;

    // DataReceiver
    boost::python::class_<OrbitFetcher::DataReceiver>("DataReceiver")
        .def(boost::python::init<>())  // No-argument constructor
        .def(boost::python::init<OrbitFetcher::Config&>())  // Constructor with Config
        .def("getTle", getTleNoArgs)
        .def("getTle", getTleWithArgs)
        .def("getSatellitePosition", getSatellitePositionNoArgs)
        .def("getSatellitePosition", getSatellitePositionWithArgs)
        .def("getSatelliteVisualPass", getSatelliteVisualPassNoArgs)
        .def("getSatelliteVisualPass", getSatelliteVisualWithArgs)
        .def("getSatelliteRadioPass", getSatelliteRadioPassNoArgs)
        .def("getSatelliteRadioPass", getSatelliteRadioWithArgs)
        .def("getSatellitesAbove", getSatellitesAboveNoArgs)
        .def("getSatellitesAbove", getSatellitesAboveWithArgs);

    // Response Data
    boost::python::class_<OrbitFetcher::ResponseData::TleLineOne>("TleLineOne")
        .def_readonly("lineNumber", &OrbitFetcher::ResponseData::TleLineOne::lineNumber)
        .def_readonly("satelliteNumber", &OrbitFetcher::ResponseData::TleLineOne::satelliteNumber)
        .def_readonly("classification", &OrbitFetcher::ResponseData::TleLineOne::classification)
        .def_readonly("intlDesignatorLaunchYear", &OrbitFetcher::ResponseData::TleLineOne::intlDesignatorLaunchYear)
        .def_readonly("intlDesignatorLaunchNumberOfYear", &OrbitFetcher::ResponseData::TleLineOne::intlDesignatorLaunchNumberOfYear)
        .def_readonly("intlDesignatorPieceOfLaunch", &OrbitFetcher::ResponseData::TleLineOne::intlDesignatorPieceOfLaunch)
        .def_readonly("epochYear", &OrbitFetcher::ResponseData::TleLineOne::epochYear)
        .def_readonly("epochDay", &OrbitFetcher::ResponseData::TleLineOne::epochDay)
        .def_readonly("firstDerivativeMeanMotion", &OrbitFetcher::ResponseData::TleLineOne::firstDerivativeMeanMotion)
        .def_readonly("secondDerivativeMeanMotion", &OrbitFetcher::ResponseData::TleLineOne::secondDerivativeMeanMotion)
        .def_readonly("bStarDragCoefficient", &OrbitFetcher::ResponseData::TleLineOne::bStarDragCoefficient)
        .def_readonly("ephemerisType", &OrbitFetcher::ResponseData::TleLineOne::ephemerisType)
        .def_readonly("elementSetNumber", &OrbitFetcher::ResponseData::TleLineOne::elementSetNumber)
        .def_readonly("checkSum", &OrbitFetcher::ResponseData::TleLineOne::checkSum);

    boost::python::class_<OrbitFetcher::ResponseData::TleLineTwo>("TleLineTwo")
        .def_readonly("lineNumber", &OrbitFetcher::ResponseData::TleLineTwo::lineNumber)
        .def_readonly("satelliteNumber", &OrbitFetcher::ResponseData::TleLineTwo::satelliteNumber)
        .def_readonly("inclinationDegrees", &OrbitFetcher::ResponseData::TleLineTwo::inclinationDegrees)
        .def_readonly("rightAscensionDegrees", &OrbitFetcher::ResponseData::TleLineTwo::rightAscensionDegrees)
        .def_readonly("orbitEccentricity", &OrbitFetcher::ResponseData::TleLineTwo::orbitEccentricity)
        .def_readonly("argumentOfPerigee", &OrbitFetcher::ResponseData::TleLineTwo::argumentOfPerigee)
        .def_readonly("meanAnomalyDegrees", &OrbitFetcher::ResponseData::TleLineTwo::meanAnomalyDegrees)
        .def_readonly("meanMotion", &OrbitFetcher::ResponseData::TleLineTwo::meanMotion)
        .def_readonly("totalRevolutionsAtEpoch", &OrbitFetcher::ResponseData::TleLineTwo::totalRevolutionsAtEpoch)
        .def_readonly("checkSum", &OrbitFetcher::ResponseData::TleLineTwo::checkSum);

    boost::python::class_<OrbitFetcher::ResponseData::TleData>("TleData")
        .def_readonly("tleLineOne", &OrbitFetcher::ResponseData::TleData::tleLineOne)
        .def_readonly("tleLineTwo", &OrbitFetcher::ResponseData::TleData::tleLineTwo);

    boost::python::class_<OrbitFetcher::ResponseData::TleStrings>("TleStrings")
        .def_readonly("lineOne", &OrbitFetcher::ResponseData::TleStrings::lineOne)
        .def_readonly("lineTow", &OrbitFetcher::ResponseData::TleStrings::lineTwo)
        .def_readonly("complete", &OrbitFetcher::ResponseData::TleStrings::complete);

    boost::python::class_<OrbitFetcher::ResponseData::Tle>("Tle")
        .def_readonly("satId", &OrbitFetcher::ResponseData::Tle::satId)
        .def_readonly("satName", &OrbitFetcher::ResponseData::Tle::satName)
        .def_readonly("transactionCount", &OrbitFetcher::ResponseData::Tle::transactionCount)
        .def_readonly("tleStrings", &OrbitFetcher::ResponseData::Tle::tleStrings)
        .def_readonly("tleData", &OrbitFetcher::ResponseData::Tle::tleData);

    boost::python::class_<OrbitFetcher::ResponseData::PositionData>("PositionData")
        .def_readonly("lat", &OrbitFetcher::ResponseData::PositionData::lat)
        .def_readonly("lon", &OrbitFetcher::ResponseData::PositionData::lon)
        .def_readonly("altKm", &OrbitFetcher::ResponseData::PositionData::altKm)
        .def_readonly("azimuth", &OrbitFetcher::ResponseData::PositionData::azimuth)
        .def_readonly("elevation", &OrbitFetcher::ResponseData::PositionData::elevation)
        .def_readonly("rightAscension", &OrbitFetcher::ResponseData::PositionData::rightAscension)
        .def_readonly("declination", &OrbitFetcher::ResponseData::PositionData::declination)
        .def_readonly("timeStamp", &OrbitFetcher::ResponseData::PositionData::timeStamp);

    boost::python::class_<std::vector<OrbitFetcher::ResponseData::PositionData>>("PositionDataVector")
        .def(boost::python::vector_indexing_suite<std::vector<OrbitFetcher::ResponseData::PositionData>>());

    boost::python::class_<OrbitFetcher::ResponseData::SatellitePosition>("SatellitePosition")
        .def_readonly("satId", &OrbitFetcher::ResponseData::SatellitePosition::satId)
        .def_readonly("satName", &OrbitFetcher::ResponseData::SatellitePosition::satName)
        .def_readonly("transactionCount", &OrbitFetcher::ResponseData::SatellitePosition::transactionCount)
        .def_readonly("positionData", &OrbitFetcher::ResponseData::SatellitePosition::positionData);

    boost::python::class_<OrbitFetcher::ResponseData::VisualPassData>("VisualPassData")
        .def_readonly("startAzimuth", &OrbitFetcher::ResponseData::VisualPassData::startAzimuth)
        .def_readonly("startAzimuthCompass", &OrbitFetcher::ResponseData::VisualPassData::startAzimuthCompass)
        .def_readonly("startElevation", &OrbitFetcher::ResponseData::VisualPassData::startElevation)
        .def_readonly("startUTC", &OrbitFetcher::ResponseData::VisualPassData::startUTC)
        .def_readonly("maxAzimuth", &OrbitFetcher::ResponseData::VisualPassData::maxAzimuth)
        .def_readonly("maxAzimuthCompass", &OrbitFetcher::ResponseData::VisualPassData::maxAzimuthCompass)
        .def_readonly("maxElevation", &OrbitFetcher::ResponseData::VisualPassData::maxElevation)
        .def_readonly("maxUTC", &OrbitFetcher::ResponseData::VisualPassData::maxUTC)
        .def_readonly("endAzimuth", &OrbitFetcher::ResponseData::VisualPassData::endAzimuth)
        .def_readonly("endAzimuthCompass", &OrbitFetcher::ResponseData::VisualPassData::endAzimuthCompass)
        .def_readonly("endElevation", &OrbitFetcher::ResponseData::VisualPassData::endElevation)
        .def_readonly("endUTC", &OrbitFetcher::ResponseData::VisualPassData::endUTC)
        .def_readonly("maxVisualMagnitude", &OrbitFetcher::ResponseData::VisualPassData::maxVisualMagnitude)
        .def_readonly("visibleDuration", &OrbitFetcher::ResponseData::VisualPassData::visibleDuration);

    boost::python::class_<std::vector<OrbitFetcher::ResponseData::VisualPassData>>("VisualPassDataVector")
        .def(boost::python::vector_indexing_suite<std::vector<OrbitFetcher::ResponseData::VisualPassData>>());

    boost::python::class_<OrbitFetcher::ResponseData::SatelliteVisualPass>("SatelliteVisualPass")
        .def_readonly("satId", &OrbitFetcher::ResponseData::SatelliteVisualPass::satId)
        .def_readonly("satName", &OrbitFetcher::ResponseData::SatelliteVisualPass::satName)
        .def_readonly("transactionCount", &OrbitFetcher::ResponseData::SatelliteVisualPass::transactionCount)
        .def_readonly("passCount", &OrbitFetcher::ResponseData::SatelliteVisualPass::passCount)
        .def_readonly("visualPassData", &OrbitFetcher::ResponseData::SatelliteVisualPass::visualPassData);

    boost::python::class_<OrbitFetcher::ResponseData::RadioPassData>("RadioPassData")
        .def_readonly("startAzimuth", &OrbitFetcher::ResponseData::RadioPassData::startAzimuth)
        .def_readonly("startAzimuthCompass", &OrbitFetcher::ResponseData::RadioPassData::startAzimuthCompass)
        .def_readonly("startUTC", &OrbitFetcher::ResponseData::RadioPassData::startUTC)
        .def_readonly("maxAzimuth", &OrbitFetcher::ResponseData::RadioPassData::maxAzimuth)
        .def_readonly("maxAzimuthCompass", &OrbitFetcher::ResponseData::RadioPassData::maxAzimuthCompass)
        .def_readonly("maxElevation", &OrbitFetcher::ResponseData::RadioPassData::maxElevation)
        .def_readonly("maxUTC", &OrbitFetcher::ResponseData::RadioPassData::maxUTC)
        .def_readonly("endAzimuth", &OrbitFetcher::ResponseData::RadioPassData::endAzimuth)
        .def_readonly("endAzimuthCompass", &OrbitFetcher::ResponseData::RadioPassData::endAzimuthCompass)
        .def_readonly("endUTC", &OrbitFetcher::ResponseData::RadioPassData::endUTC);

    boost::python::class_<std::vector<OrbitFetcher::ResponseData::RadioPassData>>("RadioPassDataVector")
        .def(boost::python::vector_indexing_suite<std::vector<OrbitFetcher::ResponseData::RadioPassData>>());

    boost::python::class_<OrbitFetcher::ResponseData::SatelliteRadioPass>("SatelliteRadioPass")
        .def_readonly("satId", &OrbitFetcher::ResponseData::SatelliteRadioPass::satId)
        .def_readonly("satName", &OrbitFetcher::ResponseData::SatelliteRadioPass::satName)
        .def_readonly("transactionCount", &OrbitFetcher::ResponseData::SatelliteRadioPass::transactionCount)
        .def_readonly("passCount", &OrbitFetcher::ResponseData::SatelliteRadioPass::passCount)
        .def_readonly("radioPassData", &OrbitFetcher::ResponseData::SatelliteRadioPass::radioPassData);

     boost::python::class_<OrbitFetcher::ResponseData::SatelliteData>("SatelliteData")
        .def_readonly("satId", &OrbitFetcher::ResponseData::SatelliteData::satId)
        .def_readonly("satName", &OrbitFetcher::ResponseData::SatelliteData::satName)
        .def_readonly("internationalDesignator", &OrbitFetcher::ResponseData::SatelliteData::internationalDesignator)
        .def_readonly("launchDate", &OrbitFetcher::ResponseData::SatelliteData::launchDate)
        .def_readonly("lat", &OrbitFetcher::ResponseData::SatelliteData::lat)
        .def_readonly("lon", &OrbitFetcher::ResponseData::SatelliteData::lon)
        .def_readonly("altKm", &OrbitFetcher::ResponseData::SatelliteData::altKm);
    
    boost::python::class_<std::vector<OrbitFetcher::ResponseData::SatelliteData>>("SatelliteDataVector")
        .def(boost::python::vector_indexing_suite<std::vector<OrbitFetcher::ResponseData::SatelliteData>>());

    boost::python::class_<OrbitFetcher::ResponseData::SatellitesAbove>("SatellitesAbove")
        .def_readonly("category", &OrbitFetcher::ResponseData::SatellitesAbove::category)
        .def_readonly("transactionCount", &OrbitFetcher::ResponseData::SatellitesAbove::transactionCount)
        .def_readonly("satelliteCount", &OrbitFetcher::ResponseData::SatellitesAbove::satelliteCount)
        .def_readonly("satellitesAbove", &OrbitFetcher::ResponseData::SatellitesAbove::satellitesAbove);
}