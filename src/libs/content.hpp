#ifndef CONTENT
#define CONTENT

#include <fstream>
#include <cstring>
#include <unordered_map>
#include "json.hpp"

using json = nlohmann::json;

class Content
{
private:
public:
    // Data
    std::unordered_map<int, json> ItemContents;

    // Methods
    void ReadContent(std::string);
};

#endif
