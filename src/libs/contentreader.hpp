#ifndef CONTENTREADER
#define CONTENTREADER
#include <unordered_map>
#include "json.hpp"

using json = nlohmann::json;

class ContentReader
{
private:
public:
    // Data
    std::unordered_map<int, json> ItemContents;

    // Methods
    void ReadContent(std::string);
};

#endif
