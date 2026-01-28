#include <boost/test/unit_test.hpp>
#include "OrbitFetcher/TleParser.h"
#include "TleParserFixture.h"

BOOST_AUTO_TEST_CASE(testParseTleExponentialFieldPlusSigned)
{
    const auto data = OrbitFetcher::TleParser::parseTleExponentialField("1234-5");
    BOOST_CHECK_EQUAL(OrbitFetcher::Utilities::approximatelyEqualAbsRel(data, 0.000001234, OrbitFetcher::Utilities::absEps, OrbitFetcher::Utilities::relEps), true);
}

BOOST_AUTO_TEST_CASE(testParseTleExponentialFieldNegativeSigned)
{
    const auto data = OrbitFetcher::TleParser::parseTleExponentialField("-1234-5");
    BOOST_CHECK_EQUAL(OrbitFetcher::Utilities::approximatelyEqualAbsRel(data, -0.000001234, OrbitFetcher::Utilities::absEps, OrbitFetcher::Utilities::relEps), true);
}

BOOST_AUTO_TEST_CASE(testParseTleExponentialFieldDoubleDigitExponent)
{
    const auto data = OrbitFetcher::TleParser::parseTleExponentialField("-1234-10");
    BOOST_CHECK_EQUAL(OrbitFetcher::Utilities::approximatelyEqualAbsRel(data, -0.00000000001234, OrbitFetcher::Utilities::absEps, OrbitFetcher::Utilities::relEps), true);
}

BOOST_AUTO_TEST_CASE(testLineOneToLong)
{
    std::string tle{"1 25544U 98067A   18077.09047010  .00001878  00000-0  35621-4 0  9999 \r\n2 25544  51.6412 112.8495 0001928 208.4187 178.9720 15.54106440104358"};
    BOOST_CHECK_THROW(OrbitFetcher::TleParser::parseTleString(tle), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(testLineOneToShort)
{
    std::string tle{"1 25544U 98067A   18077.09047010  .00001878  00000-0  35621-4 0  999\r\n2 25544  51.6412 112.8495 0001928 208.4187 178.9720 15.54106440104358"};
    BOOST_CHECK_THROW(OrbitFetcher::TleParser::parseTleString(tle), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(testTwoOneToLong)
{
    const std::string tle{"1 25544U 98067A   18077.09047010  .00001878  00000-0  35621-4 0  9999\r\n2 25544  51.6412 112.8495 0001928 208.4187 178.9720 15.54106440104358 "};
    BOOST_CHECK_THROW(OrbitFetcher::TleParser::parseTleString(tle), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(testLineTwoToShort)
{
    const std::string tle{"1 25544U 98067A   18077.09047010  .00001878  00000-0  35621-4 0  9999\r\n2 25544  51.6412 112.8495 0001928 208.4187 178.9720 15.5410644010435"};
    BOOST_CHECK_THROW(OrbitFetcher::TleParser::parseTleString(tle), std::runtime_error);
}

// Line One Tests
BOOST_FIXTURE_TEST_CASE(checkTleLineOneLineNumber, TleParserFixture)
{
    BOOST_CHECK_EQUAL(tleData.tleLineOne.lineNumber, 1);
}

BOOST_FIXTURE_TEST_CASE(checkTleLineOneSatelliteNumber, TleParserFixture)
{
    BOOST_CHECK_EQUAL(tleData.tleLineOne.satelliteNumber, 25544);
}

BOOST_FIXTURE_TEST_CASE(checkTleLineOneClassification, TleParserFixture)
{
    BOOST_CHECK_EQUAL(tleData.tleLineOne.classification, 'U');
}

BOOST_FIXTURE_TEST_CASE(checkTleLineOneIntlDesignatorLaunchYear, TleParserFixture)
{
    BOOST_CHECK_EQUAL(tleData.tleLineOne.intlDesignatorLaunchYear, 98);
}

BOOST_FIXTURE_TEST_CASE(checkTleLineOneIntlDesignatorLaunchNumberOfYear, TleParserFixture)
{
    BOOST_CHECK_EQUAL(tleData.tleLineOne.intlDesignatorLaunchNumberOfYear, 67);
}

BOOST_FIXTURE_TEST_CASE(checkTleLineOneIntlDesignatorPieceOfLaunch, TleParserFixture)
{
    BOOST_CHECK_EQUAL(tleData.tleLineOne.intlDesignatorPieceOfLaunch, "A  ");
}

BOOST_FIXTURE_TEST_CASE(checkTleLineOneEpochYear, TleParserFixture)
{
    BOOST_CHECK_EQUAL(tleData.tleLineOne.epochYear, 18);
}

BOOST_FIXTURE_TEST_CASE(checkTleLineOneEpochDay, TleParserFixture)
{
    BOOST_CHECK_EQUAL(OrbitFetcher::Utilities::approximatelyEqualAbsRel(tleData.tleLineOne.epochDay, 077.09047010, OrbitFetcher::Utilities::absEps, OrbitFetcher::Utilities::relEps), true);
}

BOOST_FIXTURE_TEST_CASE(checkTleLineOneFirstDerivativeMeanMotion, TleParserFixture)
{
    BOOST_CHECK_EQUAL(OrbitFetcher::Utilities::approximatelyEqualAbsRel(tleData.tleLineOne.firstDerivativeMeanMotion, 0.00001878, OrbitFetcher::Utilities::absEps, OrbitFetcher::Utilities::relEps), true);
}

BOOST_FIXTURE_TEST_CASE(checkTleLineOneSecondDerivativeMeanMotion, TleParserFixture)
{
    BOOST_CHECK_EQUAL(OrbitFetcher::Utilities::approximatelyEqualAbsRel(tleData.tleLineOne.secondDerivativeMeanMotion, 0.0, OrbitFetcher::Utilities::absEps, OrbitFetcher::Utilities::relEps), true);
}

BOOST_FIXTURE_TEST_CASE(checkTleLineOneBStarDragCoefficient, TleParserFixture)
{
    BOOST_CHECK_EQUAL(OrbitFetcher::Utilities::approximatelyEqualAbsRel(tleData.tleLineOne.bStarDragCoefficient, 0.000035621, OrbitFetcher::Utilities::absEps, OrbitFetcher::Utilities::relEps), true);
}

BOOST_FIXTURE_TEST_CASE(checkTleLineOneEphemerisType, TleParserFixture)
{
    BOOST_CHECK_EQUAL(tleData.tleLineOne.ephemerisType, 0);
}

BOOST_FIXTURE_TEST_CASE(checkTleLineOneElementSetNumber, TleParserFixture)
{
    BOOST_CHECK_EQUAL(tleData.tleLineOne.elementSetNumber, 999);
}

BOOST_FIXTURE_TEST_CASE(checkTleLineOneCheckSum, TleParserFixture)
{
    BOOST_CHECK_EQUAL(tleData.tleLineOne.checkSum, 9);
}

// Line Two Tests
BOOST_FIXTURE_TEST_CASE(checkTleLineTwoLineNumber, TleParserFixture)
{
    BOOST_CHECK_EQUAL(tleData.tleLineTwo.lineNumber, 2);
}

BOOST_FIXTURE_TEST_CASE(checkTleLineTwoSatelliteNumber, TleParserFixture)
{
    BOOST_CHECK_EQUAL(tleData.tleLineTwo.satelliteNumber, 25544);
}

BOOST_FIXTURE_TEST_CASE(checkTleLineTwoInclinationDegrees, TleParserFixture)
{
    BOOST_CHECK_EQUAL(OrbitFetcher::Utilities::approximatelyEqualAbsRel(tleData.tleLineTwo.inclinationDegrees, 51.6412, OrbitFetcher::Utilities::absEps, OrbitFetcher::Utilities::relEps), true);
}

BOOST_FIXTURE_TEST_CASE(checkTleLineTwoRightAscensionDegrees, TleParserFixture)
{
    BOOST_CHECK_EQUAL(OrbitFetcher::Utilities::approximatelyEqualAbsRel(tleData.tleLineTwo.rightAscensionDegrees, 112.8495, OrbitFetcher::Utilities::absEps, OrbitFetcher::Utilities::relEps), true);
}

BOOST_FIXTURE_TEST_CASE(checkTleLineTwoOrbitEccentricity, TleParserFixture)
{
    BOOST_CHECK_EQUAL(OrbitFetcher::Utilities::approximatelyEqualAbsRel(tleData.tleLineTwo.orbitEccentricity, 0.0001928, OrbitFetcher::Utilities::absEps, OrbitFetcher::Utilities::relEps), true);
}

BOOST_FIXTURE_TEST_CASE(checkTleLineTwoArgumentOfPerigee, TleParserFixture)
{
    BOOST_CHECK_EQUAL(OrbitFetcher::Utilities::approximatelyEqualAbsRel(tleData.tleLineTwo.argumentOfPerigee, 208.4187, OrbitFetcher::Utilities::absEps, OrbitFetcher::Utilities::relEps), true);
}

BOOST_FIXTURE_TEST_CASE(checkTleLineTwoMeanAnomalyDegrees, TleParserFixture)
{
    BOOST_CHECK_EQUAL(OrbitFetcher::Utilities::approximatelyEqualAbsRel(tleData.tleLineTwo.meanAnomalyDegrees, 178.9720, OrbitFetcher::Utilities::absEps, OrbitFetcher::Utilities::relEps), true);
}

BOOST_FIXTURE_TEST_CASE(checkTleLineTwoMeanMotion, TleParserFixture)
{
    BOOST_CHECK_EQUAL(OrbitFetcher::Utilities::approximatelyEqualAbsRel(tleData.tleLineTwo.meanMotion, 15.54106440, OrbitFetcher::Utilities::absEps, OrbitFetcher::Utilities::relEps), true);
}

BOOST_FIXTURE_TEST_CASE(checkTleLineTwoTotalRevolutionsAtEpoch, TleParserFixture)
{
    BOOST_CHECK_EQUAL(tleData.tleLineTwo.totalRevolutionsAtEpoch, 10435);
}

BOOST_FIXTURE_TEST_CASE(checkTleLineTwoCheckSum, TleParserFixture)
{
    BOOST_CHECK_EQUAL(tleData.tleLineTwo.checkSum, 8);
}
