class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int curr = 0;

        for (int i = cost.size() - 1; i >= 0; i = i - 3) {
            if (i == 0) {
                curr = curr + cost[0];
            } else {
                curr = curr + cost[i] + cost[i - 1];
            }
        }
        return curr;
    }
};