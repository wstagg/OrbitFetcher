#include <boost/test/unit_test.hpp> 
#include "../../include/OrbitFetcher/Config.h"

BOOST_AUTO_TEST_CASE(testConfigReadValidFilePath)
{
    OrbitFetcher::Config config{};
    BOOST_CHECK_NO_THROW(config.read("../config.txt"));
};

BOOST_AUTO_TEST_CASE(testConfigReadInvalidFilePath)
{
    OrbitFetcher::Config config{};
    BOOST_CHECK_THROW(config.read(""), std::runtime_error);
};

BOOST_AUTO_TEST_CASE(testConfigMissingConfigFileValue)
{
    OrbitFetcher::Config config{};
    BOOST_CHECK_THROW(config.read("../config_tests.txt"), std::runtime_error);
};