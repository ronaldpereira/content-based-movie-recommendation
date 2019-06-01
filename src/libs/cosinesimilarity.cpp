#include "cosinesimilarity.hpp"

std::unordered_map<int, double> CosineSimilarity::calculateSimilarity(ItemUser *itemuser, int targetItemID)
{
    std::unordered_map<int, double> similarities;

    if (computedSimilarities.find(targetItemID) == computedSimilarities.end())
    {
        std::unordered_map<int, int> &targetItemRatings = itemuser->ItemUserRatings[targetItemID];

        for (auto &item : itemuser->ItemUserRatings)
        {
            int itemID = item.first;

            if (itemID == targetItemID)
                continue;

            std::unordered_map<int, int> &userRatings = item.second;

            double weightedRatingSum = 0;
            double squaredRatingsUser1 = 0, squaredRatingsUser2 = 0;

            for (auto &user : targetItemRatings)
            {
                int userID = user.first;

                if (userRatings.find(userID) == userRatings.end())
                    continue;

                weightedRatingSum += (itemuser->ItemUserRatings[targetItemID][userID] - itemuser->ItemAvgRating[targetItemID]) * (itemuser->ItemUserRatings[itemID][userID] - itemuser->ItemAvgRating[itemID]);
                squaredRatingsUser1 += std::pow(itemuser->ItemUserRatings[targetItemID][userID] - itemuser->ItemAvgRating[targetItemID], 2);
                squaredRatingsUser2 += std::pow(itemuser->ItemUserRatings[itemID][userID] - itemuser->ItemAvgRating[itemID], 2);
            }

            double normalizer = std::sqrt(squaredRatingsUser1 * squaredRatingsUser2);

            if (normalizer != 0)
                similarities[itemID] = weightedRatingSum / normalizer;
        }

        // Saves the target item computed similarities for possible future use
        computedSimilarities[targetItemID] = similarities;
    }

    else
        similarities = computedSimilarities[targetItemID];

    return similarities;
}
