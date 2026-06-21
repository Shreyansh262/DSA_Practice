class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int prev = intervals[0][1];
        int start = intervals[0][0];
        int end = prev;
        vector<vector<int>> ans;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= prev) {
                end = max(end, intervals[i][1]);
                prev = end;
            } else {
                end = prev;
                ans.push_back({start, end});
                start = intervals[i][0];
                prev = intervals[i][1];
                end = prev;
            }
        }
        if (ans.size() == 0 || ans[ans.size() - 1][1] != end)
            ans.push_back({start, end});
        return ans;
    }
};