#include "content.hpp"

using json = nlohmann::json;

void Content::ReadContent(std::string contentsPath)
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

    preProcess();
}

void Content::preProcess()
{
    for (auto &item : itemContents)
    {
        int itemID = item.first;

        std::string year = item.second.value("Year", "");
        std::string metascore = item.second.value("Metascore", "");
        std::string imdbRating = item.second.value("imdbRating", "");
        std::string imdbVotes = item.second.value("imdbVotes", "");

        FeaturesItem["Year"][itemID] = convertStringToInt(year);
        FeaturesItem["Metascore"][itemID] = convertStringToDouble(metascore);
        FeaturesItem["imdbRating"][itemID] = convertStringToDouble(imdbRating);
        FeaturesItem["imdbVotes"][itemID] = convertStringToInt(imdbVotes);
    }
}

int Content::convertStringToInt(std::string str)
{
    if (str.compare("N/A") != 0 && !str.empty())
        return stoi(str);

    else
        return 0;
}

double Content::convertStringToDouble(std::string str)
{
    if (str.compare("N/A") != 0 && !str.empty())
        return stod(str);

    else
        return 0.0;
}
