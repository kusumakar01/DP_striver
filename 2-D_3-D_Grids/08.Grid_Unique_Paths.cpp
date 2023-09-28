/*
Given a matrix m x n, return the number of possible unique paths to reach the bottom-right corner from top-left corner.
*/

// Approach 1: Recursion

// Approach 2: DP - All versions

int uniquePaths(int m, int n) {
    vector<int> cur(n, 1);
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            cur[j] += cur[j - 1];
    return cur[n - 1];
}

// Approach 3: Combinatorics
int uniquePaths(int m, int n) {
    double N = n + m - 2, r = m - 1, res = 1, i;
    for (i = 1; i <= r; i++)
        res = res * (N - r + i) / i;
    return round(res);
}


/*
We want to choose (m-1) positions out of (m+n-2) for 'D' and fill the rest with 'R'.
Therefore, the number of unique paths is equal to "the number of ways to choose (m-1) positions out of (m+n-2)" or (n+m-2)C(m-1).
*/