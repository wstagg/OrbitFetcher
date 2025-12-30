#include <boost/test/unit_test.hpp> 
#include "../../include/OrbitFetcher/Config.h"
#include "unitTestFixtures.h"

BOOST_AUTO_TEST_CASE(testConfigFileReadValidFilePath)
{
    OrbitFetcher::Config config{};
    BOOST_CHECK_NO_THROW(config.read("../config.txt"));
};

BOOST_AUTO_TEST_CASE(testConfigFileReadInvalidFilePath)
{
    OrbitFetcher::Config config{};
    BOOST_CHECK_THROW(config.read(""), std::runtime_error);
};

BOOST_FIXTURE_TEST_CASE(testConfigFileApiKeyMissingValue, ConfigTestFixture)
{
    OrbitFetcher::Config config{};
    writeTestConfigFile("API_KEY =");
    BOOST_CHECK_THROW(config.read(fileName), std::invalid_argument);
};

BOOST_FIXTURE_TEST_CASE(testConfigFileObserverLatMissingValue, ConfigTestFixture)
{
    OrbitFetcher::Config config{};
    writeTestConfigFile("OBSERVER_LAT =");
    BOOST_CHECK_THROW(config.read(fileName), std::invalid_argument);
};

BOOST_FIXTURE_TEST_CASE(testConfigFileObserverLonMissingValue, ConfigTestFixture)
{
    OrbitFetcher::Config config{};
    writeTestConfigFile("OBSERVER_LON =");
    BOOST_CHECK_THROW(config.read(fileName), std::invalid_argument);
};

BOOST_FIXTURE_TEST_CASE(testConfigFileObserverAltMissingValue, ConfigTestFixture)
{
    OrbitFetcher::Config config{};
    writeTestConfigFile("OBSERVER_ALT =");
    BOOST_CHECK_THROW(config.read(fileName), std::invalid_argument);
};

BOOST_FIXTURE_TEST_CASE(testConfigFileSearchRadiusMissingValue, ConfigTestFixture)
{
    OrbitFetcher::Config config{};
    writeTestConfigFile("SEARCH_RAD =");
    BOOST_CHECK_THROW(config.read(fileName), std::invalid_argument);
};

BOOST_FIXTURE_TEST_CASE(testConfigFileNoradIdMissingValue, ConfigTestFixture)
{
    OrbitFetcher::Config config{};
    writeTestConfigFile("NORAD_ID =");
    BOOST_CHECK_THROW(config.read(fileName), std::invalid_argument);
};

BOOST_FIXTURE_TEST_CASE(testConfigFileSearchCatergoryMissingValue, ConfigTestFixture)
{
    OrbitFetcher::Config config{};
    writeTestConfigFile("SEARCH_CATEGORY =");
    BOOST_CHECK_THROW(config.read(fileName), std::invalid_argument);
};

BOOST_FIXTURE_TEST_CASE(testConfigFileSecondsMissingValue, ConfigTestFixture)
{
    OrbitFetcher::Config config{};
    writeTestConfigFile("SECONDS =");
    BOOST_CHECK_THROW(config.read(fileName), std::invalid_argument);
};

BOOST_FIXTURE_TEST_CASE(testConfigFileDaysMissingValue, ConfigTestFixture)
{
    OrbitFetcher::Config config{};
    writeTestConfigFile("DAYS =");
    BOOST_CHECK_THROW(config.read(fileName), std::invalid_argument);
};

BOOST_FIXTURE_TEST_CASE(testConfigFileMinimumVisibilityMissingValue, ConfigTestFixture)
{
    OrbitFetcher::Config config{};
    writeTestConfigFile("MIN_VISIBILITY =");
    BOOST_CHECK_THROW(config.read(fileName), std::invalid_argument);
};

BOOST_FIXTURE_TEST_CASE(testConfigFileMinimumElevationMissingValue, ConfigTestFixture)
{
    OrbitFetcher::Config config{};
    writeTestConfigFile("MIN_ELEVATION =");
    BOOST_CHECK_THROW(config.read(fileName), std::invalid_argument);
};

BOOST_FIXTURE_TEST_CASE(testConfigFileObserverLatInvalidCharacters, ConfigTestFixture)
{
    OrbitFetcher::Config config{};
    writeTestConfigFile("OBSERVER_LAT = 50.a456");
    BOOST_CHECK_THROW(config.read(fileName), std::invalid_argument);
};

BOOST_FIXTURE_TEST_CASE(testConfigFileObserverLonInvalidCharacters, ConfigTestFixture)
{
    OrbitFetcher::Config config{};
    writeTestConfigFile("OBSERVER_LON = 123.xyz789");
    BOOST_CHECK_THROW(config.read(fileName), std::invalid_argument);
};

BOOST_FIXTURE_TEST_CASE(testConfigFileObserverAltInvalidCharacters, ConfigTestFixture)
{
    OrbitFetcher::Config config{};
    writeTestConfigFile("OBSERVER_ALT = 100.abc");
    BOOST_CHECK_THROW(config.read(fileName), std::invalid_argument);
};

BOOST_FIXTURE_TEST_CASE(testConfigFileSearchRadInvalidCharacters, ConfigTestFixture)
{
    OrbitFetcher::Config config{};
    writeTestConfigFile("SEARCH_RAD = 45abc");
    BOOST_CHECK_THROW(config.read(fileName), std::invalid_argument);
};

BOOST_FIXTURE_TEST_CASE(testConfigFileNoradIdInvalidCharacters, ConfigTestFixture)
{
    OrbitFetcher::Config config{};
    writeTestConfigFile("NORAD_ID = 25544xyz");
    BOOST_CHECK_THROW(config.read(fileName), std::invalid_argument);
};

BOOST_FIXTURE_TEST_CASE(testConfigFileSearchCategoryInvalidCharacters, ConfigTestFixture)
{
    OrbitFetcher::Config config{};
    writeTestConfigFile("SEARCH_CATEGORY = 10abc");
    BOOST_CHECK_THROW(config.read(fileName), std::invalid_argument);
};

BOOST_FIXTURE_TEST_CASE(testConfigFileSecondsInvalidCharacters, ConfigTestFixture)
{
    OrbitFetcher::Config config{};
    writeTestConfigFile("SECONDS = 120xyz");
    BOOST_CHECK_THROW(config.read(fileName), std::invalid_argument);
};

BOOST_FIXTURE_TEST_CASE(testConfigFileDaysInvalidCharacters, ConfigTestFixture)
{
    OrbitFetcher::Config config{};
    writeTestConfigFile("DAYS = 5abc");
    BOOST_CHECK_THROW(config.read(fileName), std::invalid_argument);
};

BOOST_FIXTURE_TEST_CASE(testConfigFileMinVisibilityInvalidCharacters, ConfigTestFixture)
{
    OrbitFetcher::Config config{};
    writeTestConfigFile("MIN_VISIBILITY = 100xyz");
    BOOST_CHECK_THROW(config.read(fileName), std::invalid_argument);
};

BOOST_FIXTURE_TEST_CASE(testConfigFileMinElevationInvalidCharacters, ConfigTestFixture)
{
    OrbitFetcher::Config config{};
    writeTestConfigFile("MIN_ELEVATION = 30abc");
    BOOST_CHECK_THROW(config.read(fileName), std::invalid_argument);
};