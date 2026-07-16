class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> prefixGcd;
        int mxi = 0;
        for(int i = 0;i<nums.size();i++){
            mxi = max(mxi,nums[i]);
            int x = __gcd(nums[i],mxi);
            prefixGcd.push_back(x);
        }
        int n = prefixGcd.size();
        sort(prefixGcd.begin(),prefixGcd.end());
        long long sum = 0;
        for(int i = 0;i<(n>>1);i++){
            sum+= __gcd(prefixGcd[i],prefixGcd[n-i-1]);
        }
        return sum;
    }
};