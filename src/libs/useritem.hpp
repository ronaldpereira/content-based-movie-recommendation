#ifndef USERITEM
#define USERITEM

#include <fstream>
#include <cstring>
#include <unordered_map>

class UserItem
{
private:
    void calculateUsersAvgRating();
    void calculateItemsAvgRating();
    void calculateGlobalItemsAvgRating();

public:
    // Data
    std::unordered_map<int, std::unordered_map<int, int>> UserItemRatings;
    std::unordered_map<int, std::unordered_map<int, int>> ItemUserRatings;
    std::unordered_map<int, double> UserAvgRating;
    std::unordered_map<int, double> ItemAvgRating;
    double GlobalItemsAvg;

    // Methods
    void UserItemRatingsBuilder(char *);
};

#endif
