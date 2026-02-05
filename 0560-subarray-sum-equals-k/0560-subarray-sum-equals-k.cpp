class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<long, int> mpp;
        long currS = 0, c = 0;
        for (int i = 0; i < nums.size(); i++) {
            currS += nums[i];
            if (currS == k) {
                c++;
            }
            long rem = currS - k;
            if (mpp.find(rem) != mpp.end()) {
                c += mpp[rem];
            }
            mpp[currS]++;
        }
        return c;
    }
};