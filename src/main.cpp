#include "libs/content.hpp"
#include "libs/itemuser.hpp"
#include "libs/prediction.hpp"

int main(int argc, char **argv)
{
    // Unused parameter 'argc' warning suppression
    (void)argc;

    Content content;
    ItemUser itemuser;
    Prediction prediction;

    content.ReadContent(argv[1]);

    itemuser.ItemUserRatingsBuilder(argv[2]);

    prediction.GetPredictions(argv[3], &itemuser, &content);

    return 0;
}
