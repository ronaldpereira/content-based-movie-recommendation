#include "rocchio.hpp"

void Rocchio::BuildUserFeature(int targetItemID, int targetUserID, UserItem *useritem, Content *content)
{
    if (UserFeature.find(targetUserID) == UserFeature.end())
    {
        for (auto &user : useritem->UserItemRatings)
        {
            
        }
    }
}
