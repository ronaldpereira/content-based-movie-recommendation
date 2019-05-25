# Content-based Movie Recommendation

Content-based Movie Recommendation algorithm.

## Tools

## Tools

Movie Recommendation task by using:

- Content-based Similarities
- Collaborative Filtering rating previews
- Matrix Mean Normalization
- Adjusted Cosine Distance
- k-Nearest Neighbors selection for computed similarities (default: k = 0 (disabled))
- Item cold-start:
  1. Uses item average rating as the <user, item> prediction
  2. If the item average doesn't exists, uses global items average rating as the <user, item> prediction
  
## Evaluation Metric
  
- Accuracy metric: RMSE (Root Mean Squared Error)

## Leaderboard

The leaderboard can be seen in this [Kaggle Competition](https://www.kaggle.com/c/recsys-20191-cbmr/leaderboard)
