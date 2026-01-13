#include <boost/test/unit_test.hpp> 
#include "../../include/OrbitFetcher/Config.h"
#include "ConfigTestFixture.h"
#include "OrbitFetcher/DataReceiver.h"

BOOST_AUTO_TEST_CASE(testDataReceiverGetTleEmtpyApiKey)
{
    OrbitFetcher::DataReceiver dataReceiver;
    BOOST_CHECK_THROW(dataReceiver.getTle("", 25544), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testDataReceiverGetTleInvalidNoradId)
{
    OrbitFetcher::DataReceiver dataReceiver;
    BOOST_CHECK_THROW(dataReceiver.getTle("abc", 0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testDataReceivergetSatellitePositionEmptyApiKey)
{
    OrbitFetcher::DataReceiver dataReceiver;
    BOOST_CHECK_THROW(dataReceiver.getSatellitePosition("", 25544, 50.0, 50.0, 0, 10), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testDataReceivergetSatellitePositionInvalidNoradId)
{
    OrbitFetcher::DataReceiver dataReceiver;
    BOOST_CHECK_THROW(dataReceiver.getSatellitePosition("abc", 0, 50.0, 50.0, 0, 10), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testDataReceivergetSatellitePositionLatToHigh)
{
    OrbitFetcher::DataReceiver dataReceiver;
    BOOST_CHECK_THROW(dataReceiver.getSatellitePosition("abc", 25544, 91.0, 50.0, 0, 10), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(testDataReceivergetSatellitePositionLatToLow)
{
    OrbitFetcher::DataReceiver dataReceiver;
    BOOST_CHECK_THROW(dataReceiver.getSatellitePosition("abc", 25544, -91.0, 50.0, 0, 10), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(testDataReceivergetSatellitePositionLonToHigh)
{
    OrbitFetcher::DataReceiver dataReceiver;
    BOOST_CHECK_THROW(dataReceiver.getSatellitePosition("abc", 25544, 90.0, 181.0, 0, 10), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(testDataReceivergetSatellitePositionLonToLow)
{
    OrbitFetcher::DataReceiver dataReceiver;
    BOOST_CHECK_THROW(dataReceiver.getSatellitePosition("abc", 25544, 90.0, -181.0, 0, 10), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(testDataReceivergetSatellitePositionSecondsToHigh)
{
    OrbitFetcher::DataReceiver dataReceiver;
    BOOST_CHECK_THROW(dataReceiver.getSatellitePosition("abc", 25544, 90.0, 180.0, 0, 301), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(testDataReceivergetSatellitePositionSecondsToLow)
{
    OrbitFetcher::DataReceiver dataReceiver;
    BOOST_CHECK_THROW(dataReceiver.getSatellitePosition("abc", 25544, 90.0, 180.0, 0, 0), std::out_of_range);
}

// getSatelliteVisualPass tests
BOOST_AUTO_TEST_CASE(testDataReceiverGetSatelliteVisualPassEmptyApiKey)
{
    OrbitFetcher::DataReceiver dataReceiver;
    BOOST_CHECK_THROW(dataReceiver.getSatelliteVisualPass("", 25544, 50.0, 50.0, 0, 5, 300), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testDataReceiverGetSatelliteVisualPassInvalidNoradId)
{
    OrbitFetcher::DataReceiver dataReceiver;
    BOOST_CHECK_THROW(dataReceiver.getSatelliteVisualPass("abc", 0, 50.0, 50.0, 0, 5, 300), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testDataReceiverGetSatelliteVisualPassLatTooHigh)
{
    OrbitFetcher::DataReceiver dataReceiver;
    BOOST_CHECK_THROW(dataReceiver.getSatelliteVisualPass("abc", 25544, 91.0, 50.0, 0, 5, 300), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(testDataReceiverGetSatelliteVisualPassLatTooLow)
{
    OrbitFetcher::DataReceiver dataReceiver;
    BOOST_CHECK_THROW(dataReceiver.getSatelliteVisualPass("abc", 25544, -91.0, 50.0, 0, 5, 300), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(testDataReceiverGetSatelliteVisualPassLonTooHigh)
{
    OrbitFetcher::DataReceiver dataReceiver;
    BOOST_CHECK_THROW(dataReceiver.getSatelliteVisualPass("abc", 25544, 50.0, 181.0, 0, 5, 300), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(testDataReceiverGetSatelliteVisualPassLonTooLow)
{
    OrbitFetcher::DataReceiver dataReceiver;
    BOOST_CHECK_THROW(dataReceiver.getSatelliteVisualPass("abc", 25544, 50.0, -181.0, 0, 5, 300), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(testDataReceiverGetSatelliteVisualPassDaysTooHigh)
{
    OrbitFetcher::DataReceiver dataReceiver;
    BOOST_CHECK_THROW(dataReceiver.getSatelliteVisualPass("abc", 25544, 50.0, 50.0, 0, 11, 300), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(testDataReceiverGetSatelliteVisualPassDaysTooLow)
{
    OrbitFetcher::DataReceiver dataReceiver;
    BOOST_CHECK_THROW(dataReceiver.getSatelliteVisualPass("abc", 25544, 50.0, 50.0, 0, 0, 300), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(testDataReceiverGetSatelliteVisualPassMinimumVisibilityTooLow)
{
    OrbitFetcher::DataReceiver dataReceiver;
    BOOST_CHECK_THROW(dataReceiver.getSatelliteVisualPass("abc", 25544, 50.0, 50.0, 0, 5, 0), std::out_of_range);
}

// getSatelliteRadioPass tests
BOOST_AUTO_TEST_CASE(testDataReceiverGetSatelliteRadioPassEmptyApiKey)
{
    OrbitFetcher::DataReceiver dataReceiver;
    BOOST_CHECK_THROW(dataReceiver.getSatelliteRadioPass("", 25544, 50.0, 50.0, 0, 5, 10), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testDataReceiverGetSatelliteRadioPassInvalidNoradId)
{
    OrbitFetcher::DataReceiver dataReceiver;
    BOOST_CHECK_THROW(dataReceiver.getSatelliteRadioPass("abc", 0, 50.0, 50.0, 0, 5, 10), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testDataReceiverGetSatelliteRadioPassLatTooHigh)
{
    OrbitFetcher::DataReceiver dataReceiver;
    BOOST_CHECK_THROW(dataReceiver.getSatelliteRadioPass("abc", 25544, 91.0, 50.0, 0, 5, 10), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(testDataReceiverGetSatelliteRadioPassLatTooLow)
{
    OrbitFetcher::DataReceiver dataReceiver;
    BOOST_CHECK_THROW(dataReceiver.getSatelliteRadioPass("abc", 25544, -91.0, 50.0, 0, 5, 10), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(testDataReceiverGetSatelliteRadioPassLonTooHigh)
{
    OrbitFetcher::DataReceiver dataReceiver;
    BOOST_CHECK_THROW(dataReceiver.getSatelliteRadioPass("abc", 25544, 50.0, 181.0, 0, 5, 10), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(testDataReceiverGetSatelliteRadioPassLonTooLow)
{
    OrbitFetcher::DataReceiver dataReceiver;
    BOOST_CHECK_THROW(dataReceiver.getSatelliteRadioPass("abc", 25544, 50.0, -181.0, 0, 5, 10), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(testDataReceiverGetSatelliteRadioPassDaysTooHigh)
{
    OrbitFetcher::DataReceiver dataReceiver;
    BOOST_CHECK_THROW(dataReceiver.getSatelliteRadioPass("abc", 25544, 50.0, 50.0, 0, 11, 10), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(testDataReceiverGetSatelliteRadioPassDaysTooLow)
{
    OrbitFetcher::DataReceiver dataReceiver;
    BOOST_CHECK_THROW(dataReceiver.getSatelliteRadioPass("abc", 25544, 50.0, 50.0, 0, 0, 10), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(testDataReceiverGetSatelliteRadioPassMinimumElevationTooLow)
{
    OrbitFetcher::DataReceiver dataReceiver;
    BOOST_CHECK_THROW(dataReceiver.getSatelliteRadioPass("abc", 25544, 50.0, 50.0, 0, 5, 0), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(testDataReceiverGetSatelliteRadioPassMinimumElevationTooHigh)
{
    OrbitFetcher::DataReceiver dataReceiver;
    BOOST_CHECK_THROW(dataReceiver.getSatelliteRadioPass("abc", 25544, 50.0, 50.0, 0, 5, 361), std::out_of_range);
}

// getSatellitesAbove tests
BOOST_AUTO_TEST_CASE(testDataReceiverGetSatellitesAboveEmptyApiKey)
{
    OrbitFetcher::DataReceiver dataReceiver;
    BOOST_CHECK_THROW(dataReceiver.getSatellitesAbove("", 50.0, 50.0, 0, 45, OrbitFetcher::SearchCategory::All), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testDataReceiverGetSatellitesAboveLatTooHigh)
{
    OrbitFetcher::DataReceiver dataReceiver;
    BOOST_CHECK_THROW(dataReceiver.getSatellitesAbove("abc", 91.0, 50.0, 0, 45, OrbitFetcher::SearchCategory::All), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(testDataReceiverGetSatellitesAboveLatTooLow)
{
    OrbitFetcher::DataReceiver dataReceiver;
    BOOST_CHECK_THROW(dataReceiver.getSatellitesAbove("abc", -91.0, 50.0, 0, 45, OrbitFetcher::SearchCategory::All), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(testDataReceiverGetSatellitesAboveLonTooHigh)
{
    OrbitFetcher::DataReceiver dataReceiver;
    BOOST_CHECK_THROW(dataReceiver.getSatellitesAbove("abc", 50.0, 181.0, 0, 45, OrbitFetcher::SearchCategory::All), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(testDataReceiverGetSatellitesAboveLonTooLow)
{
    OrbitFetcher::DataReceiver dataReceiver;
    BOOST_CHECK_THROW(dataReceiver.getSatellitesAbove("abc", 50.0, -181.0, 0, 45, OrbitFetcher::SearchCategory::All), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(testDataReceiverGetSatellitesAboveSearchRadiusTooLow)
{
    OrbitFetcher::DataReceiver dataReceiver;
    BOOST_CHECK_THROW(dataReceiver.getSatellitesAbove("abc", 50.0, 50.0, 0, 0, OrbitFetcher::SearchCategory::All), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(testDataReceiverGetSatellitesAboveSearchRadiusTooHigh)
{
    OrbitFetcher::DataReceiver dataReceiver;
    BOOST_CHECK_THROW(dataReceiver.getSatellitesAbove("abc", 50.0, 50.0, 0, 91, OrbitFetcher::SearchCategory::All), std::out_of_range);
}