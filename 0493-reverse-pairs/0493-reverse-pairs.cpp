using ll = long long;
class Solution {
public:
    int merge(int low, int mid, int high, vector<int>& arr) {
        int cnt = 0;
        int n1 = mid - low + 1, n2 = high - mid;
        vector<int> l(n1), h(n2);
        for (int i = 0; i < n1; i++) {
            l[i] = arr[i + low];
        }
        for (int i = 0; i < n2; i++) {
            h[i] = arr[i + mid + 1];
        }
        for (ll i : h) {
            long long x = upper_bound(l.begin(), l.end(), 2*i) - l.begin();
            if (x != n1) {
                cnt += n1 - x;
            }
        }
        int i = 0, j = 0;
        int k = low;
        while (i < n1 && j < n2) {
            if (l[i] <= h[j]) {
                arr[k] = l[i];
                i++;
            } else {
                arr[k] = h[j];
                j++;
            }
            k++;
        }
        while (i < n1) {
            arr[k] = l[i];
            i++;
            k++;
        }
        while (j < n2) {
            arr[k] = h[j];
            k++;
            j++;
        }
        return cnt;
    }
    int mergeSort(int low, int high, vector<int>& arr) {
        if (low >= high)
            return 0;
        int mid = low + (high - low) / 2;
        int x = mergeSort(low, mid, arr);
        int y = mergeSort(mid + 1, high, arr);
        return x + y + merge(low, mid, high, arr);
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(0,nums.size()-1,nums);
    }
};
