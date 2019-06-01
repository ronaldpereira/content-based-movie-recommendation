#ifndef CONTENT
#define CONTENT

#include <iostream>
#include <fstream>
#include <cstring>
#include <unordered_map>
#include "json.hpp"

using json = nlohmann::json;

class Content
{
private:
    // Data
    std::unordered_map<int, json> itemContents;

    // Methods
    void preProcess();
    int convertStringToInt(std::string);
    double convertStringToDouble(std::string);

public:
    // Data
    std::unordered_map<std::string, std::unordered_map<int, double>> FeaturesItem;

    // Methods
    void ReadContent(std::string);
};

#endif
