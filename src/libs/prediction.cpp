#include "prediction.hpp"

void Prediction::GetPredictions(char *targetsPath, UserItem *useritem, Content *content)
{
    int user = 0, item = 0;
    double ratingPrediction = 0;
    char *token = NULL;
    std::string line;

    std::ifstream targetsFile;
    targetsFile.open(targetsPath);

    Rocchio rocchio;

    // Discard header from csv
    getline(targetsFile, line);

    // Print header
    std::cout << "UserId:ItemId,Prediction" << std::endl;

    while (getline(targetsFile, line) && !line.empty())
    {
        char *cstr = new char[line.length() + 1];
        std::strcpy(cstr, line.c_str());

        token = strtok(cstr, ",ui");
        user = atoi(token);

        token = strtok(NULL, ",ui");
        item = atoi(token);

        ratingPrediction = makePrediction(user, item, useritem, content, &rocchio);

        std::cout << "u" << std::setfill('0') << std::setw(7) << user;
        std::cout << ":i" << std::setfill('0') << std::setw(7) << item;
        std::cout << "," << std::setprecision(15) << ratingPrediction;
        std::cout << std::endl;
    }

    targetsFile.close();
}

double Prediction::makePrediction(int targetUserID, int targetItemID, UserItem *useritem, Content *content, Rocchio *rocchio)
{
    double predRating = 0;
    double numerator = 0;
    double squaredUserFeatures = 0, squaredItemFeatures = 0;

    rocchio->BuildUserFeature(targetUserID, useritem, content);

    for (auto &feature : rocchio->UserFeature[targetUserID])
    {
        std::string featureID = feature.first;

        if (rocchio->UserFeature.find(targetUserID) == rocchio->UserFeature.end())
            continue;

        numerator += rocchio->UserFeature[targetUserID][featureID] * content->FeaturesItem[featureID][targetItemID];
        squaredUserFeatures += std::pow(rocchio->UserFeature[targetUserID][featureID], 2);
        squaredItemFeatures += std::pow(content->FeaturesItem[featureID][targetItemID], 2);
    }

    double normalizer = std::sqrt(squaredUserFeatures) * std::sqrt(squaredItemFeatures);

    if (normalizer != 0)
        predRating = numerator * 10 / normalizer;

    if (predRating != 0)
    {
        // Exploding ratings corrections
        if (predRating > 10)
            predRating = 10;

        else if (predRating < 0)
            predRating = 0;
    }

    // If the target item doesn't have any content-based similarity with any other item, pick the user average rating
    else
    {
        predRating = useritem->UserAvgRating[targetUserID];

        // If the user is a complete cold-start, uses the global users average
        if (predRating == 0)
            predRating = useritem->GlobalUsersAvg;
    }

    return predRating;
}
