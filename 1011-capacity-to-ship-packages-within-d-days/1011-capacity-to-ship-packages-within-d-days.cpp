class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int high = accumulate(weights.begin(),weights.end(),0);
        int low = *max_element(weights.begin(),weights.end());
        int cap;
        while(low<=high){
            int mid = high - (high - low)/2;
            if(daysRequired(weights,mid) <= days){
                high = mid-1;
                cap = mid;
            }
            else {
                low = mid +1;
            }
        }
        return cap;
    }
    int daysRequired(vector<int>& weights, int cap){
        int days = 1;
        int dcap = cap;
        for(int i : weights){
            if(dcap>=i){
                dcap -= i;
            }
            else{
                days++;
                dcap = cap - i;
            }
        }
        return days;
    }
};