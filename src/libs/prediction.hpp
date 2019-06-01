#ifndef PREDICTION
#define PREDICTION

#include <cmath>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <unordered_map>
#include "useritem.hpp"
#include "content.hpp"
#include "rocchio.hpp"

class Prediction
{
private:
    double makePrediction(int, int, UserItem *, Content *, Rocchio *);

public:
    void GetPredictions(char *, UserItem *, Content *);
};

#endif
