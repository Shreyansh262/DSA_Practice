class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0;
        set<int> s;
        for(int i = 0; i< nums.size(); i++){
            s.emplace(nums[i]);
        }
        int k = s.size(); 
        for (auto it = s.begin(); it != s.end(); it++){
            nums[l] = *it;
            l++;
        }
        return k;
    }
};