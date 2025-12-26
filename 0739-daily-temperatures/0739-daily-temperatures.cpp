class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        set<pair<int, int>> waitingList; 
        for (int i = 0; i < n; i++) {
            int currentTemp = temperatures[i];
            while (!waitingList.empty() && currentTemp > waitingList.begin()->first) {               
                int prevIndex = waitingList.begin()->second;
                ans[prevIndex] = i - prevIndex;
                waitingList.erase(waitingList.begin());
            }
            waitingList.insert({currentTemp, i});
        }
        return ans;
    }
};