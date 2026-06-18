class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int x = INT_MIN, y = INT_MIN;
        int cx = 0, cy = 0;
        int n = nums.size();
        for (int i : nums) {
            if (cx == 0 && i != y) {
                cx = 1;
                x = i;
            } else if (cy == 0 && i != x) {
                cy = 1;
                y = i;
            } else if (i == x) {
                cx++;
            } else if (i == y) {
                cy++;
            } else {
                cx--;
                cy--;
            }
        }
        cx = 0,cy = 0;
        for(int j:nums){
            if(j==x) cx++;
            if(j==y)cy++;
        }

        vector<int>ans;
        if(cx>n/3) ans.push_back(x);
        if(cy>n/3) ans.push_back(y);
        return ans;

        // unordered_map <int,int> store;
        // vector <int> ans;
        // for(int i : nums){
        //     store[i]++;
        // }
        // for(auto it = store.begin();it!=store.end();it++){
        //     if((*it).second>nums.size()/3){
        //         ans.push_back((*it).first);
        //     }
        // }
        // return ans;
    }
};