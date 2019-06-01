#include "useritem.hpp"

void UserItem::UserItemRatingsBuilder(char *ratingsPath)
{
    std::string line;
    std::ifstream ratingsFile;
    ratingsFile.open(ratingsPath);

    // Discard header from csv
    getline(ratingsFile, line);

    while (getline(ratingsFile, line) && !line.empty())
    {
        char *token;

        char *cstr = new char[line.length() + 1];
        std::strcpy(cstr, line.c_str());

        token = strtok(cstr, ",ui");
        int user = atoi(token);

        token = strtok(NULL, ",ui");
        int item = atoi(token);

        token = strtok(NULL, ",ui");
        int rating = atoi(token);

        UserItemRatings[user][item] = rating;
    }

    calculateUsersAvgRating();
    calculateGlobalUsersAvgRating();

    ratingsFile.close();
}

void UserItem::calculateUsersAvgRating()
{
    for (auto &user : UserItemRatings)
    {
        int sum = 0;
        int count = 0;
        for (auto &item : user.second)
        {
            sum += item.second;
            count++;
        }
        UserAvgRating[user.first] = double(sum) / count;
    }
}

void UserItem::calculateGlobalUsersAvgRating()
{
    double sum = 0;
    int count = 0;
    for (auto &user : UserAvgRating)
    {
        sum += user.second;
        count++;
    }
    GlobalUsersAvg = double(sum) / count;
}
