#pragma once
#include <fstream>
#include <filesystem>
#include <string>

struct ConfigTestFixture
{
    std::ofstream testConfigFile;
    std::string fileName {"testConfig.txt"};

    ConfigTestFixture()
    {
        testConfigFile.open(fileName, std::ofstream::out | std::ofstream::trunc);
    }

    ~ConfigTestFixture()
    {
        std::filesystem::remove(fileName);
    }

    void writeTestConfigFile(const std::string& text)
    {
        testConfigFile << text;
        testConfigFile.close();
    }
};