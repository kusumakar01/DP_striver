#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
   int result = 0, prev2 = 0, prev = abs(heights[1] - heights[0]);
   for(int i = 2; i < n; i++){
      result = min(prev + abs(heights[i] - heights[i - 1]), prev2 + abs(heights[i] - heights[i - 2]));
      prev2 = prev;
      prev = result;
   }
   return result;
}

/*
modified fibonacci like
*/