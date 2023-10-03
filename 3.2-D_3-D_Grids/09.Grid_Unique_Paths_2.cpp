/*
Ostacle and space are marked as 1 or 0 respectively in m x n grid.
A path that the robot takes cannot include any square that is an obstacle.
Return the number of possible unique paths that the robot can take to reach the bottom-right corner from top-left corner.
*/

// Approach 1: Recursion

// Approach 2: DP - All varaints

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<int> dp(n);
    dp[0] = 1;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++){
            if(obstacleGrid[i][j]){
                dp[j] = 0;
                continue;
            }
            if(!i && !j) continue;
            dp[j] += j > 0 ? dp[j - 1] : 0;
        }
    return dp[n - 1];
}

