cmake_minimum_required(VERSION 3.20.0)

project(OrbitFetcher)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
option(BUILD_PY_BINDINGS "Build Python bindings" OFF)

enable_testing()

# Set CMP0167 to OLD to use the legacy FindBoost module
if(POLICY CMP0167)
    cmake_policy(SET CMP0167 OLD)
endif()

find_package(CURL REQUIRED)
find_package(nlohmann_json REQUIRED)
find_package(Boost REQUIRED COMPONENTS unit_test_framework)

set(SOURCES
    cpp/DataReceiver.cpp
    cpp/Config.cpp
    cpp/JsonParser.cpp
    cpp/TleParser.cpp
    cpp/Utilities.cpp)

if (BUILD_PY_BINDINGS)
    find_package(Boost REQUIRED COMPONENTS python)
    find_package(Python3 REQUIRED COMPONENTS Interpreter Development)
    list(APPEND SOURCES cpp/pythonInterface.cpp)
endif ()

add_library(OrbitFetcher SHARED ${SOURCES})

target_include_directories(OrbitFetcher PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include)

set_target_properties(OrbitFetcher PROPERTIES PREFIX "")

if (BUILD_PY_BINDINGS AND WIN32)
    set_target_properties(OrbitFetcher PROPERTIES SUFFIX ".pyd")
endif ()

set (LIBS
    CURL::libcurl
    nlohmann_json::nlohmann_json
    Boost::unit_test_framework)

if (BUILD_PY_BINDINGS)
    list(APPEND LIBS
        Boost::python
        Python3::Python)
endif ()

target_link_libraries(OrbitFetcher ${LIBS})

# Unit tests
add_executable(OrbitFetcherTests
        tests/cpp/OrbitFetcherTestsMain.cpp
        tests/cpp/ConfigTests.cpp
        tests/cpp/DataReceiverTests.cpp)

target_include_directories(OrbitFetcherTests PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/fixtures)

target_link_libraries(OrbitFetcherTests OrbitFetcher)

# Integration tests
add_executable(OrbitFetcherIntegrationTests
        tests/cpp/OrbitFetcherTestsMain.cpp
        tests/cpp/integrationTests.cpp)

target_include_directories(OrbitFetcherIntegrationTests PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/fixtures)

target_link_libraries(OrbitFetcherIntegrationTests OrbitFetcher)

add_test(NAME OrbitFetcherTests COMMAND OrbitFetcherTests)
add_test(NAME OrbitFetcherIntegrationTests COMMAND OrbitFetcherIntegrationTests)

# copies the orbitFetcherConfig.txt to the build dir
add_custom_command(TARGET OrbitFetcherTests POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/orbitFetcherConfig.txt
        $<TARGET_FILE_DIR:OrbitFetcherTests>)