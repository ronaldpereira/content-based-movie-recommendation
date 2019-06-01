#include "libs/contentreader.hpp"
#include "libs/itemuser.hpp"
#include "libs/prediction.hpp"

int main(int argc, char **argv)
{
    // Unused parameter 'argc' warning suppression
    (void)argc;

    // K Nearest Neighbors selection
    // int kNearestNeighbors = 0;

    // ItemUser itemuser;
    // Prediction prediction;
    ContentReader content;

    content.ReadContent(argv[1]);

    // itemuser.ItemUserRatingsBuilder(argv[2]);

    // prediction.GetPredictions(argv[3], &itemuser, kNearestNeighbors);

    return 0;
}
