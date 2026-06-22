class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int x = m-1,y=n-1;
        while(x>=0&&y>=0){
            if(nums1[x]>nums2[y]){
                nums1[x+y+1] = nums1[x];
                x--;
            }
            else{
                nums1[x+y+1] = nums2[y];
                y--;
            }
        }
        for(int i = x;i>=0;i--){
            nums1[i+y+1] = nums1[i];
        }
        for(int i = y;i>=0;i--){
            nums1[x+i+1] = nums2[i];
        }
    }
};