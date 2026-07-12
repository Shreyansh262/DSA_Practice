class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> copy = arr;
        sort(copy.begin(),copy.end());
        int r = 1;
        int prev = INT_MIN;
        unordered_map<int,int> rank;
        for(int i:copy){
            if(i == prev) continue;
            rank.insert({i,r});
            r++;
            prev = i;
        }
        vector<int>ans;
        for(int i = 0;i<arr.size();i++){
            auto it = rank.find(arr[i]);
            ans.push_back(it->second);
        }
        return ans;
    }
};