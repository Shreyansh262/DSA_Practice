class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long)m * k > (long)bloomDay.size())
            return -1;
        int ans = -1;
        int low = 1, high = *max_element(bloomDay.begin(), bloomDay.end());
        while (low <= high) {
            int mid = high - (high - low) / 2;
            if (checkDay(bloomDay, m, k, mid)) {
                high = mid - 1;
                ans = mid;
            } else
                low = mid + 1;
        }
        return ans;
    }
    bool checkDay(vector<int>& bloomDay, int M, int K, int day) {
        int m = M, k = K;
        for (int i : bloomDay) {
            if (i <= day) {
                k--;
                if (k == 0) {
                    m--;
                    k = K;
                }
            } else {
                k = K;
            }
            if (m == 0)
                break;
        }
        if (m == 0)
            return true;
        return false;
    }
};