/*
We are given an array ‘ARR’ with N positive integers. We need to find if there is a subset in “ARR” with a sum equal to K.
If there is a subset like this, return true else return false.
*/

// Space Optimized Tabulation

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<int> dp(k + 1, false), curr(k + 1);
    curr[0] = dp[0] = true;
    if(arr[0] <= k) dp[arr[0]] = true;
    for(int index = 1; index < n; index++){
        for(int target = 1; target <= k; target++){
            bool notTake = dp[target];
            bool take = false;
            if(arr[index] <= target) take = dp[target - arr[index]];
            curr[target] = take || notTake;
        }
        dp = curr;
    }
    return curr[k];
}

// Tabulation

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(k + 1, false));
    for(int index = 0; index < n; index++) dp[index][0] = true;
    if(arr[0] <= k) dp[0][arr[0]] = true;
    for(int index = 1; index < n; index++){
        for(int target = 1; target <= k; target++){
            bool notTake = dp[index - 1][target];
            bool take = false;
            if(arr[index] <= target) take = dp[index - 1][target - arr[index]];
            dp[index][target] = take || notTake;
        }
    }
    return dp[n - 1][k];
}

// Memoization

bool help(int index, int target, vector<vector<int>> &dp, vector<int> &arr) {
    if(!target) return true;
    if(target < 0 || index < 0) return false;
    if(dp[index][target] != -1) return dp[index][target];
    return dp[index][target] = help(index - 1, target - arr[index], dp, arr) || help(index - 1, target, dp, arr);
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return help(n - 1, k, dp, arr);
}

//Recursion

bool help(int index, int target, vector<int> &arr) {
    if(!target) return true;
    if(target < 0 || index < 0) return false;
    return help(index - 1, target - arr[index], arr) || help(index - 1, target, arr);
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    return help(n - 1, k, arr);
}