#include "libs/content.hpp"
#include "libs/useritem.hpp"
#include "libs/prediction.hpp"

int main(int argc, char **argv)
{
    // Unused parameter 'argc' warning suppression
    (void)argc;

    Content content;
    UserItem useritem;
    Prediction prediction;

    content.ReadContent(argv[1]);

    useritem.UserItemRatingsBuilder(argv[2]);

    prediction.GetPredictions(argv[3], &useritem, &content);

    return 0;
}
