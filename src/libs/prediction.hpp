#ifndef PREDICTION
#define PREDICTION
#include "cosinesimilarity.hpp"
#include "itemuser.hpp"

class Prediction
{
private:
    double makePrediction(int, int, ItemUser *, CosineSimilarity *);

public:
    void GetPredictions(char *, ItemUser *);
};

#endif
