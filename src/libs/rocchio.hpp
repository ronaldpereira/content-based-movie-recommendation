#ifndef ROCCHIO
#define ROCCHIO

#include <unordered_map>
#include "useritem.hpp"
#include "content.hpp"
#include "json.hpp"

class Rocchio
{
private:
public:
    // Data
    std::unordered_map<int, std::unordered_map<std::string, double>> UserFeature;

    // Methods
    void BuildUserFeature(int, UserItem *, Content *);
};

#endif
