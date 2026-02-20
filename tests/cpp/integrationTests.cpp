#include <boost/test/unit_test.hpp>
#include "integrationTestFixtures.h"

BOOST_FIXTURE_TEST_CASE(testGetTle, DataReceiverFixture)
{
    auto tle = dataReceiver->getTle(apiKey, noradId);
    BOOST_TEST(tle.satId == noradId);
    BOOST_TEST(!tle.satName.empty());
    BOOST_TEST(tle.transactionCount >= 0);
    BOOST_TEST(!tle.tleStrings.complete.empty());
}

BOOST_FIXTURE_TEST_CASE(testGetSatellitePosition, DataReceiverFixture)
{
    auto satellitePositions = dataReceiver->getSatellitePosition(
        apiKey,
        noradId,
        observerLat,
        observerLon,
        observerAlt,
        seconds);

    BOOST_TEST(satellitePositions.satId == noradId);
    BOOST_TEST(!satellitePositions.satName.empty());
    BOOST_TEST(satellitePositions.transactionCount >= 0);
    BOOST_TEST(satellitePositions.positionData.size() == seconds);
};

BOOST_FIXTURE_TEST_CASE(testGetSatelliteVisualPass, DataReceiverFixture)
{
    auto satelliteVisualPass = dataReceiver->getSatelliteVisualPass(
        apiKey,
        noradId,
        observerLat,
        observerLon,
        observerAlt,
        days,
        minimumVisibility);

    BOOST_TEST(satelliteVisualPass.satId == noradId);
    BOOST_TEST(!satelliteVisualPass.satName.empty());
    BOOST_TEST(satelliteVisualPass.transactionCount >= 0);
    BOOST_TEST(satelliteVisualPass.passCount == satelliteVisualPass.visualPassData.size());
};

BOOST_FIXTURE_TEST_CASE(testGetSatelliteRadioPass, DataReceiverFixture)
{
    auto satelliteRadioPass = dataReceiver->getSatelliteRadioPass(
        apiKey,
        noradId,
        observerLat,
        observerLon,
        observerAlt,
        days,
        minimumElevation);
    BOOST_TEST(satelliteRadioPass.satId == noradId);
    BOOST_TEST(!satelliteRadioPass.satName.empty());
    BOOST_TEST(satelliteRadioPass.transactionCount >= 0);
    BOOST_TEST(satelliteRadioPass.passCount == satelliteRadioPass.radioPassData.size());
};

BOOST_FIXTURE_TEST_CASE(testGetSatellitesAbove, DataReceiverFixture)
{
    auto satellitesAbove = dataReceiver->getSatellitesAbove(
        apiKey,
        observerLat,
        observerLon,
        observerAlt,
        searchRadius,
        OrbitFetcher::SearchCategory::All);
    BOOST_TEST(satellitesAbove.transactionCount >= 0);
    BOOST_TEST(!satellitesAbove.category.empty());
    BOOST_TEST(satellitesAbove.satelliteCount >= 0);
};

BOOST_FIXTURE_TEST_CASE(testInvalidApiKeyResponseError, DataReceiverFixture)
{
    BOOST_CHECK_THROW(dataReceiver->getTle("abcdef", noradId), std::runtime_error);
}

BOOST_FIXTURE_TEST_CASE(testInvalidNoradIdKeyResponseError, DataReceiverFixture)
{
    BOOST_CHECK_THROW(dataReceiver->getTle(apiKey, 999999), std::runtime_error);
}

BOOST_FIXTURE_TEST_CASE(testGetTleUsingConfigFile, DataReceiverWithConfigFileFixture)
{
    auto tle = dataReceiver->getTle();
    BOOST_TEST(tle.satId == config.getConfigValues().noradId);
    BOOST_TEST(!tle.satName.empty());
    BOOST_TEST(tle.transactionCount >= 0);
    BOOST_TEST(!tle.tleStrings.complete.empty());
};

// With Config file
BOOST_FIXTURE_TEST_CASE(testGetSatellitePositionUsingConfigFile, DataReceiverWithConfigFileFixture)
{
    auto satellitePositions = dataReceiver->getSatellitePosition();
    BOOST_TEST(satellitePositions.satId == config.getConfigValues().noradId);
    BOOST_TEST(!satellitePositions.satName.empty());
    BOOST_TEST(satellitePositions.transactionCount >= 0);
    BOOST_TEST(satellitePositions.positionData.size() == config.getConfigValues().seconds);
};

BOOST_FIXTURE_TEST_CASE(testGetSatelliteVisualPassUsingConfigFile, DataReceiverWithConfigFileFixture)
{
    auto satelliteVisualPass = dataReceiver->getSatelliteVisualPass();
    BOOST_TEST(satelliteVisualPass.satId == config.getConfigValues().noradId);
    BOOST_TEST(!satelliteVisualPass.satName.empty());
    BOOST_TEST(satelliteVisualPass.transactionCount >= 0);
    BOOST_TEST(satelliteVisualPass.passCount == satelliteVisualPass.visualPassData.size());
};

BOOST_FIXTURE_TEST_CASE(testGetSatelliteRadioPassUsingConfigFile, DataReceiverWithConfigFileFixture)
{
    auto satelliteRadioPass = dataReceiver->getSatelliteRadioPass();
    BOOST_TEST(satelliteRadioPass.satId == config.getConfigValues().noradId);
    BOOST_TEST(!satelliteRadioPass.satName.empty());
    BOOST_TEST(satelliteRadioPass.transactionCount >= 0);
    BOOST_TEST(satelliteRadioPass.passCount == satelliteRadioPass.radioPassData.size());
};

BOOST_FIXTURE_TEST_CASE(testGetSatellitesAboveUsingConfigFile, DataReceiverWithConfigFileFixture)
{
    auto satellitesAbove = dataReceiver->getSatellitesAbove();
    BOOST_TEST(satellitesAbove.transactionCount >= 0);
    BOOST_TEST(!satellitesAbove.category.empty());
    BOOST_TEST(satellitesAbove.satelliteCount >= 0);
};