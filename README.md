# Content-based Movie Recommendation

Content-based Movie Recommendation algorithm.

## Tools

Movie Recommendation task by using:

- Content-based Similarities using Rocchio recommendations
  - Just uses Collaborative Filtering rating previews for Rocchio calculation
- If the target item doesn't have any content-based similarity with the target user:
  1. Uses target user average rating as the <user, item> prediction
  2. If the user average doesn't exists, use target item average rating as the <user, item> prediction
  3. If the user average nor the item average doesn't exists, uses global items average rating as the <user, item> prediction
  
## Evaluation Metric
  
- Accuracy metric: RMSE (Root Mean Squared Error)

## Leaderboard

The leaderboard can be seen in this [Kaggle Competition](https://www.kaggle.com/c/recsys-20191-cbmr/leaderboard)
