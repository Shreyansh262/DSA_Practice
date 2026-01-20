class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> hold;
        for(int i = 0;i<nums1.size();i++){
            int f = 0;
            for(int j =0;j<nums2.size();j++){
                if(nums1[i]==nums2[j] && f == 0){
                    f = 1;
                    hold.push_back(-1);
                }
                else if(nums1[i]<nums2[j] && f == 1){
                    hold.pop_back();
                    hold.push_back(nums2[j]);
                    break;
                }
            }
        }
        return hold;
    }
};