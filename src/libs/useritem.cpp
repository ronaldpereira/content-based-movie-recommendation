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
        ItemUserRatings[item][user] = rating;
    }

    calculateUsersAvgRating();
    calculateItemsAvgRating();
    calculateGlobalItemsAvgRating();

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

void UserItem::calculateItemsAvgRating()
{
    for (auto &item : ItemUserRatings)
    {
        int sum = 0;
        int count = 0;
        for (auto &user : item.second)
        {
            sum += user.second;
            count++;
        }
        ItemAvgRating[item.first] = double(sum) / count;
    }
}

void UserItem::calculateGlobalItemsAvgRating()
{
    double sum = 0;
    int count = 0;
    for (auto &Item : ItemAvgRating)
    {
        sum += Item.second;
        count++;
    }
    GlobalItemsAvg = double(sum) / count;
}
