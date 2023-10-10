/*
Given an integer array nums, return true if you can partition the array into two subsets
such that the sum of the elements in both subsets is equal or false otherwise.
*/

// Space Optimized Tabulation

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        if(sum % 2) return false;
        vector<int> dp(sum / 2 + 1, false), curr(sum / 2 + 1);
        if(nums[0] <= sum / 2) dp[nums[0]] = true;
        curr[0] = dp[0] = true;
        for(int i = 1; i < nums.size(); i++){
            for(int j = 1; j <= sum / 2; j++)
                curr[j] = dp[j] || (j < nums[i] ? false : dp[j - nums[i]]);
            dp = curr;
        }
        return dp[sum / 2];
    }
};