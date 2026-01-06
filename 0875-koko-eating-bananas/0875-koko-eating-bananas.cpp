class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long st = 1, end = *max_element(piles.begin(), piles.end());
        int w = INT_MAX;
        while (st <= end) {
            int mid = end - (end - st) / 2;
            int x = 0;
            for (int i : piles) {
                if (i % mid == 0)
                    x += i / mid;
                else
                    x += i / mid + 1;
            }
            if (x <= h) {
                w = min(w, mid);
                end = mid - 1;}
                
            else
                st = mid + 1;
        }
        return w;
    }
};