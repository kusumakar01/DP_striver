class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int a = 2, b = 1;
        for (int i = 2; i < n; i++) {
            a = a + b;
            b = a - b;
        }
        return a;
    }
};


/*
similar to fibonacci
move a and b both one step ahead in every iteration
*/