#ifndef ROCCHIO
#define ROCCHIO

#include <unordered_map>
#include "useritem.hpp"
#include "content.hpp"

class Rocchio
{
private:
public:
    // Data
    std::unordered_map<int, std::unordered_map<int, double>> UserFeature;

    // Methods
    void BuildUserFeature(int, int, UserItem *, Content *);
};

#endif
