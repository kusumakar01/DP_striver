/*
Given a triangle array, return the minimum path sum from top to bottom.
For each step, you may move to an adjacent number of the row below.
More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.
*/

// Approach 1: Recursion

// Approach 2: DP - All varaints

int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size(), result = 0;
    vector<int> dp(triangle[n - 1].begin(), triangle[n - 1].end()), curr(n);
    for (int row = n - 2; row >= 0; row--) {
        for (int col = row; col >= 0; col--) {
            curr[col] = min(triangle[row][col] + dp[col], triangle[row][col] + dp[col + 1]);
        }
        dp = curr;
    }
    return dp[0];
}