#ifndef USERITEM
#define USERITEM

#include <fstream>
#include <cstring>
#include <unordered_map>
#include <vector>

class UserItem
{
private:
    void calculateUsersAvgRating();
    void calculateGlobalUsersAvgRating();

public:
    // Data
    std::unordered_map<int, std::unordered_map<int, int>> UserItemRatings;
    std::unordered_map<int, std::vector<int>> UserConsumedItems;
    std::unordered_map<int, double> UserAvgRating;
    double GlobalUsersAvg;

    // Methods
    void UserItemRatingsBuilder(char *);
};

#endif
