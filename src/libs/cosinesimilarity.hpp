#ifndef COSINESIM
#define COSINESIM

#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <unordered_map>
#include "useritem.hpp"

class CosineSimilarity
{
private:
    // Data
    std::unordered_map<int, std::unordered_map<int, double>> computedSimilarities;

public:
    std::unordered_map<int, double> calculateSimilarity(UserItem *, int);
};

#endif
