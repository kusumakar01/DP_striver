
// Recursive + Memoization
int help(vector<int> nums, vector<int>& dp, int index){
    if(index >= nums.size()) return 0;
    if(dp[index] != -1) return dp[index];
    int pick = nums[index] + help(nums, dp, index + 2);
    int notpick = help(nums, dp, index + 1);
    return dp[index] = max(pick, notpick);
}

int maximumNonAdjacentSum(vector<int> &nums){
    vector<int> dp(nums.size(), - 1);
    return help(nums, dp, 0);
}



// Best Approach - Space Optimized Tabulation
int maximumNonAdjacentSum(vector<int> &nums){
    int prev = 0, prev2 = 0, curr = 0;
    for(auto num : nums){
        curr = max(num + prev2, prev);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}