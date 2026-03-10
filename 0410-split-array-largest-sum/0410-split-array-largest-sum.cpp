class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        long s = sum(nums);
        int st = 0, end = s,ans;
        while(end>=st){
            int mid = end + (st-end)/2;
            int currS = 0;
            int ss = 1;
            int maxS = 0;
            for(int i : nums){
                currS+=i;
                if(currS>mid){
                    ss ++;
                    maxS = max(maxS,currS-i);
                    currS=i;
                }
            }
            maxS = max(maxS,currS);
            if(ss<=k){
                end = mid-1;
                ans = maxS;

            }
            else{
                st = mid+1;
            }
        }
        return ans;
    }
    int sum(vector<int> n){
        long s = 0;
        for(int i : n) s += i;
        return s;
    }
};