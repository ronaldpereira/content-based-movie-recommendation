#include "rocchio.hpp"

void Rocchio::BuildUserFeature(int targetUserID, UserItem *useritem, Content *content)
{
    if (UserFeature.find(targetUserID) == UserFeature.end())
    {
        double userFeatureNumerator = 0;
        std::unordered_map<int, int> userRatings = useritem->UserItemRatings[targetUserID];

        if (userRatings.size() > 0)
        {
            for (auto &feature : content->FeaturesItem)
            {
                std::string featureID = feature.first;

                for (auto &rating : userRatings)
                {
                    int itemID = rating.first;

                    if (feature.second.find(itemID) == feature.second.end())
                        continue;

                    userFeatureNumerator += feature.second[itemID] * rating.second;
                }
                UserFeature[targetUserID][featureID] = userFeatureNumerator / userRatings.size();
            }
        }
    }
}
