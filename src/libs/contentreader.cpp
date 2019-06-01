#include <fstream>
#include <cstring>
#include "json.hpp"
#include "contentreader.hpp"

using json = nlohmann::json;

void ContentReader::ReadContent(std::string contentsPath)
{
    std::string line;
    std::ifstream contentsFile;
    contentsFile.open(contentsPath);

    // Discard header from csv
    getline(contentsFile, line);

    while (getline(contentsFile, line) && !line.empty())
    {
        char *token;

        char *cstr = new char[line.length() + 1];
        std::strcpy(cstr, line.c_str());

        token = strtok(cstr, ",ui");
        int item = atoi(token);

        token = strtok(NULL, "");
        std::string content = token;

        itemContents[item] = json::parse(content);
    }

    contentsFile.close();
}
