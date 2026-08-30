class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mp = min_element(nums.begin(),nums.end())-nums.begin();
        int lp = max_element(nums.begin(),nums.end())-nums.begin();
        int n = nums.size();
        if(lp>mp) swap(lp,mp);
        //c1
        int x = lp+(n-mp)+1;
        //c2
        x = min(x,n-lp);
        //c3
        x = min(x,mp+1);
        return x;
    }
};