
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int curr, prev = 0, prev2 = 0, temp;
        for(int i = 1; i < nums.size(); i++){
            curr = max(nums[i] + prev2, prev);
            prev2 = prev;
            prev = curr;
        }
        temp = prev, prev = 0, prev2 = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            curr = max(nums[i] + prev2, prev);
            prev2 = prev;
            prev = curr;
        }
        return max(temp, prev);
    }
};

/*
Same as Max Sum of Non Adjacent Elements but first and last element can't be picked at a time.
So we apply the same algorithm on the array but for different ranges:
a. First to Second-last element
b. Second to Last element
*/