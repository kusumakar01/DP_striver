/*
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right.
Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
*/

// Approach 1: Recursion

// Approach 2: DP - All varaints

int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<int> dp(matrix[0].begin(), matrix[0].end()), curr(n);
    for(int i = 1; i < n; i++){
        for(int j = 0; j < n; j++){
            curr[j] = matrix[i][j] + min(dp[j], (int)min((j > 0 ? dp[j - 1] : 1e9), (j < n - 1 ? dp[j + 1] : 1e9)));
        }
        dp = curr;
    }
    return *min_element(dp.begin(), dp.end());
}