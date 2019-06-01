#ifndef COSINESIM
#define COSINESIM
#include <unordered_map>
#include "itemuser.hpp"

class CosineSimilarity
{
private:
    // Data
    std::unordered_map<int, std::unordered_map<int, double>> computedSimilarities;

public:
    std::unordered_map<int, double> calculateSimilarity(ItemUser *, int);
};

#endif
