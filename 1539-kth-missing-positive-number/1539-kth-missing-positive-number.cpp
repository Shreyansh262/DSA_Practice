class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l=arr[0]-1;
        int ans,i;
        if(l>=k){
            return k;
        }
        for(i = 1;i<arr.size();i++){
            l += (arr[i] - arr[(i-1)] - 1);
            if(l>=k){
                ans = arr[i]-(l-k)-1;
                break;
            }
        }
        if(l<k){
            ans = arr[i-1] + (k-l);
        }
        return ans;
    }
};