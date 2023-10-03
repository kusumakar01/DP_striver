/*
A Ninja has an ‘N’ Day training schedule. He has to perform one of these three activities each day.
There are merit points associated with performing an activity each day.
The same activity can’t be performed on two consecutive days.
We need to find the maximum merit points the ninja can attain in N Days.
*/

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> dp(points[0].begin(), points[0].end()), curr(points[0].size());
    for(int i = 1; i < n; i++){
        for(int j = 0, last = 0; j < points[0].size(); last = 0, j++){
          for (int k = 0; k < points[0].size(); k++) if (k != j) last = max(last, dp[k]);
          curr[j] = points[i][j] + last;
        }
        dp = curr;
    }
    return *max_element(dp.begin(), dp.end());
}