class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int i = nums[0], j = nums[nums.size() - 1];
        map<int, int> store;
        int v = -1;
        
        for (int l : nums) {
            store[l]++;
        }
        if (k != 1 && k<nums.size()) {
            if (i > j) {
                if (store[i] == 1)
                    return i;
                else if (store[j] == 1)
                    return j;
            } else if (j > i)
                if (store[j] == 1)
                    return j;
                else if (store[i] == 1)
                    return i;
        } else if(k==1){
            for (auto it : store) {
                if (it.second == 1)
                    v = max(v, it.first);
            }
        } else{
            return *max_element(nums.begin(),nums.end());
        }
        return v;
    }
};