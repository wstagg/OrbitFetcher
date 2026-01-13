#include <boost/test/unit_test.hpp> 
#include "../../include/OrbitFetcher/Config.h"
#include "ConfigTestFixture.h"

BOOST_AUTO_TEST_CASE(testConfigFileReadValidFilePath)
{
    OrbitFetcher::Config config{};
    BOOST_CHECK_NO_THROW(config.read("orbitFetcherConfig.txt"));
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

BOOST_FIXTURE_TEST_CASE(testConfigFileObserverLatInvalidFormat, ConfigTestFixture)
{
    OrbitFetcher::Config config{};
    writeTestConfigFile("OBSERVER_LAT = abcd");
    BOOST_CHECK_THROW(config.read(fileName), std::invalid_argument);
};

BOOST_FIXTURE_TEST_CASE(testConfigFileObserverLonInvalidFormat, ConfigTestFixture)
{
    OrbitFetcher::Config config{};
    writeTestConfigFile("OBSERVER_LON = abcd");
    BOOST_CHECK_THROW(config.read(fileName), std::invalid_argument);
};

BOOST_FIXTURE_TEST_CASE(testConfigFileObserverAltInvalidFormat, ConfigTestFixture)
{
    OrbitFetcher::Config config{};
    writeTestConfigFile("OBSERVER_ALT = abcd");
    BOOST_CHECK_THROW(config.read(fileName), std::invalid_argument);
};

BOOST_FIXTURE_TEST_CASE(testConfigFileSearchRadInvalidFormat, ConfigTestFixture)
{
    OrbitFetcher::Config config{};
    writeTestConfigFile("SEARCH_RAD = abcd");
    BOOST_CHECK_THROW(config.read(fileName), std::invalid_argument);
};

BOOST_FIXTURE_TEST_CASE(testConfigFileNoradIdInvalidFormat, ConfigTestFixture)
{
    OrbitFetcher::Config config{};
    writeTestConfigFile("NORAD_ID = abcd");
    BOOST_CHECK_THROW(config.read(fileName), std::invalid_argument);
};

BOOST_FIXTURE_TEST_CASE(testConfigFileSearchCategoryInvalidFormat, ConfigTestFixture)
{
    OrbitFetcher::Config config{};
    writeTestConfigFile("SEARCH_CATEGORY = abcd");
    BOOST_CHECK_THROW(config.read(fileName), std::invalid_argument);
};

BOOST_FIXTURE_TEST_CASE(testConfigFileSecondsInvalidFormat, ConfigTestFixture)
{
    OrbitFetcher::Config config{};
    writeTestConfigFile("SECONDS = abcd");
    BOOST_CHECK_THROW(config.read(fileName), std::invalid_argument);
};

BOOST_FIXTURE_TEST_CASE(testConfigFileDaysInvalidFormat, ConfigTestFixture)
{
    OrbitFetcher::Config config{};
    writeTestConfigFile("DAYS = abcd");
    BOOST_CHECK_THROW(config.read(fileName), std::invalid_argument);
};

BOOST_FIXTURE_TEST_CASE(testConfigFileMinVisibilityInvalidFormat, ConfigTestFixture)
{
    OrbitFetcher::Config config{};
    writeTestConfigFile("MIN_VISIBILITY = abcd");
    BOOST_CHECK_THROW(config.read(fileName), std::invalid_argument);
};

BOOST_FIXTURE_TEST_CASE(testConfigFileMinElevationInvalidFormat, ConfigTestFixture)
{
    OrbitFetcher::Config config{};
    writeTestConfigFile("MIN_ELEVATION = abcd");
    BOOST_CHECK_THROW(config.read(fileName), std::invalid_argument);
};

BOOST_FIXTURE_TEST_CASE(testConfigFileObserverLatTooLow, ConfigTestFixture)
{
    OrbitFetcher::Config config{};
    writeTestConfigFile("OBSERVER_LAT = -91.0");
    BOOST_CHECK_THROW(config.read(fileName), std::out_of_range);
};

BOOST_FIXTURE_TEST_CASE(testConfigFileObserverLatTooHigh, ConfigTestFixture)
{
    OrbitFetcher::Config config{};
    writeTestConfigFile("OBSERVER_LAT = 91.0");
    BOOST_CHECK_THROW(config.read(fileName), std::out_of_range);
};

// OBSERVER_LON: -180 to 180
BOOST_FIXTURE_TEST_CASE(testConfigFileObserverLonTooLow, ConfigTestFixture)
{
    OrbitFetcher::Config config{};
    writeTestConfigFile("OBSERVER_LON = -181.0");
    BOOST_CHECK_THROW(config.read(fileName), std::out_of_range);
};

BOOST_FIXTURE_TEST_CASE(testConfigFileObserverLonTooHigh, ConfigTestFixture)
{
    OrbitFetcher::Config config{};
    writeTestConfigFile("OBSERVER_LON = 181.0");
    BOOST_CHECK_THROW(config.read(fileName), std::out_of_range);
};

// SEARCH_RAD: 0 to 90
BOOST_FIXTURE_TEST_CASE(testConfigFileSearchRadTooLow, ConfigTestFixture)
{
    OrbitFetcher::Config config{};
    writeTestConfigFile("SEARCH_RAD = -1");
    BOOST_CHECK_THROW(config.read(fileName), std::out_of_range);
};

BOOST_FIXTURE_TEST_CASE(testConfigFileSearchRadTooHigh, ConfigTestFixture)
{
    OrbitFetcher::Config config{};
    writeTestConfigFile("SEARCH_RAD = 91");
    BOOST_CHECK_THROW(config.read(fileName), std::out_of_range);
};

// SEARCH_CATEGORY: 0 to 57
BOOST_FIXTURE_TEST_CASE(testConfigFileSearchCategoryTooLow, ConfigTestFixture)
{
    OrbitFetcher::Config config{};
    writeTestConfigFile("SEARCH_CATEGORY = -1");
    BOOST_CHECK_THROW(config.read(fileName), std::out_of_range);
};

BOOST_FIXTURE_TEST_CASE(testConfigFileSearchCategoryTooHigh, ConfigTestFixture)
{
    OrbitFetcher::Config config{};
    writeTestConfigFile("SEARCH_CATEGORY = 58");
    BOOST_CHECK_THROW(config.read(fileName), std::out_of_range);
};

// SECONDS: 0 to 300 (actually > 0, so lowest invalid is 0)
BOOST_FIXTURE_TEST_CASE(testConfigFileSecondsTooLow, ConfigTestFixture)
{
    OrbitFetcher::Config config{};
    writeTestConfigFile("SECONDS = 0");
    BOOST_CHECK_THROW(config.read(fileName), std::out_of_range);
};

BOOST_FIXTURE_TEST_CASE(testConfigFileSecondsTooHigh, ConfigTestFixture)
{
    OrbitFetcher::Config config{};
    writeTestConfigFile("SECONDS = 301");
    BOOST_CHECK_THROW(config.read(fileName), std::out_of_range);
};

// DAYS: 0 to 10 (actually > 0, so lowest invalid is 0)
BOOST_FIXTURE_TEST_CASE(testConfigFileDaysTooLow, ConfigTestFixture)
{
    OrbitFetcher::Config config{};
    writeTestConfigFile("DAYS = 0");
    BOOST_CHECK_THROW(config.read(fileName), std::out_of_range);
};

BOOST_FIXTURE_TEST_CASE(testConfigFileDaysTooHigh, ConfigTestFixture)
{
    OrbitFetcher::Config config{};
    writeTestConfigFile("DAYS = 11");
    BOOST_CHECK_THROW(config.read(fileName), std::out_of_range);
};

// MIN_ELEVATION: 0 to 360 (actually > 0, so lowest invalid is 0)
BOOST_FIXTURE_TEST_CASE(testConfigFileMinElevationTooLow, ConfigTestFixture)
{
    OrbitFetcher::Config config{};
    writeTestConfigFile("MIN_ELEVATION = 0");
    BOOST_CHECK_THROW(config.read(fileName), std::out_of_range);
};

BOOST_FIXTURE_TEST_CASE(testConfigFileMinElevationTooHigh, ConfigTestFixture)
{
    OrbitFetcher::Config config{};
    writeTestConfigFile("MIN_ELEVATION = 361");
    BOOST_CHECK_THROW(config.read(fileName), std::out_of_range);
};

// MIN_VISIBILITY: must be > 0 (no upper bound)
BOOST_FIXTURE_TEST_CASE(testConfigFileMinVisibilityTooLow, ConfigTestFixture)
{
    OrbitFetcher::Config config{};
    writeTestConfigFile("MIN_VISIBILITY = 0");
    BOOST_CHECK_THROW(config.read(fileName), std::invalid_argument);
};

// NORAD_ID: must be > 0 (no upper bound)
BOOST_FIXTURE_TEST_CASE(testConfigFileNoradIdTooLow, ConfigTestFixture)
{
    OrbitFetcher::Config config{};
    writeTestConfigFile("NORAD_ID = 0");
    BOOST_CHECK_THROW(config.read(fileName), std::invalid_argument);
};