/*
Given a m x n grid filled with non-negative numbers,
find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.
*/

// Approach 1: Recursion

// Approach 2: DP - All variants

int minPathSum(vector<vector<int>>& grid) {
    vector<int> dp(grid[0].size());
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            dp[j] = grid[i][j] + ((i || j) ? min(i > 0 ? dp[j] : 1e9, j > 0 ? dp[j - 1] : 1e9) : 0);
        }
    }
    return dp[grid[0].size() - 1];
}