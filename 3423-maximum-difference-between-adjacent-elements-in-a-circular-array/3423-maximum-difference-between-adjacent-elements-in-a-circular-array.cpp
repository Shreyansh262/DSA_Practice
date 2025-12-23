#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        int maxDiff = abs(nums[0]-nums[n-1]);
        for(int i = 1 ; i<n ; i++){
            int diff = abs(nums[i]-nums[i-1]);
            if (diff > maxDiff) {maxDiff = diff;}
        }
        return maxDiff;
    }
};