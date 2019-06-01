#ifndef CONTENTREADER
#define CONTENTREADER
#include <unordered_map>
#include <vector>
#include "json.hpp"

using json = nlohmann::json;

class ContentReader
{
private:
    std::unordered_map<int, json> itemContents;

public:
    void ReadContent(std::string);
};

#endif
