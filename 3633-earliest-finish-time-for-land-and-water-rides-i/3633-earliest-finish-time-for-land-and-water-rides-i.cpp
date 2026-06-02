class Solution {
public:
    int earliestFinishTime(vector<int>& lT, vector<int>& landDuration,
                           vector<int>& wT, vector<int>& waterDuration) {
        int mintime = INT_MAX;
        int n = lT.size();
        int m = wT.size();
        int curr = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (lT[i] <= wT[j]) {
                    int endTime = lT[i] + landDuration[i];
                    int delay = (endTime > wT[j]) * (endTime - wT[j]);
                    curr = delay + wT[j] + waterDuration[j];
                } else if (lT[i] >= wT[j]) {
                    int endTime = wT[j] + waterDuration[j];
                    int delay = (endTime > lT[i]) * (endTime - lT[i]);
                    curr = delay + lT[i] + landDuration[i];
                }
                mintime = min(mintime, curr);
            }
        }
        return mintime;
    }
};