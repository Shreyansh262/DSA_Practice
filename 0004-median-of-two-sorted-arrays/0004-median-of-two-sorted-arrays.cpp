class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int n = nums1.size(), m = nums2.size();
        int pivot = (n + m + 1) >> 1;
        int low = 0, high = n;
        while (low <= high) {
            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MIN, r2 = INT_MIN;
            int mid = high - (high - low) / 2;
            l1 = (mid == 0) ? INT_MIN : nums1[mid - 1],
            l2 = (pivot - mid == 0) ? INT_MIN : nums2[pivot - mid - 1];
            r1 = (mid == n) ? INT_MAX : nums1[mid],
            r2 = (pivot - mid == m) ? INT_MAX : nums2[pivot - mid];
            if (l1 <= r2 && l2 <= r1) {
                if ((m + n) % 2 == 0) {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                } else {
                    return max(l1, l2);
                }
            } else if (l1 > r2) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return 0.0;
    }
    
};