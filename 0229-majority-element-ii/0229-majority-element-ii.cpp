class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map <int,int> store;
        vector <int> ans;
        for(int i : nums){
            store[i]++;
        }
        for(auto it = store.begin();it!=store.end();it++){
            if((*it).second>nums.size()/3){
                ans.push_back((*it).first);
            }
        }
        return ans;
    }
};