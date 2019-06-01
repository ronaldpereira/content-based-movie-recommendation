#ifndef PREDICTION
#define PREDICTION

#include <cmath>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <unordered_map>
#include "itemuser.hpp"
#include "content.hpp"
#include "rocchio.hpp"

class Prediction
{
private:
    // Data
    std::unordered_map<int, std::unordered_map<int, double>> itemFeatures;
    std::unordered_map<int, std::unordered_map<int, double>> userFeatures;

    //Methods
    double makePrediction(int, int, ItemUser *, Content *);

public:
    void GetPredictions(char *, ItemUser *, Content *);
};

#endif
