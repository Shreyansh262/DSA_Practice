class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        int n1 = n/2;
        int n2 = n-n1;
        vector<int>sumA;
        for(int mask = 0;mask<(1<<n1);mask++){
            int sum = 0;
            for(int i = 0;i<n1;i++){
                if(mask&(1<<i)){
                    sum+=nums[i];
                }
            }
            sumA.push_back(sum);
        }
        vector<int>sumB;
        for(int mask = 0;mask<(1<<n2);mask++){
            int sum = 0;
            for(int i = 0;i<n2;i++){
                if(mask&&(mask&(1<<i))){
                    sum+=nums[n1+i];
                }
            }
            sumB.push_back(sum);
        }
        int minDiff = INT_MAX;
        sort(sumB.begin(),sumB.end());
        for(int i = 0;i<sumA.size();i++){
            int currSum = sumA[i];
            int rem = goal - currSum;
            int highP = upper_bound(sumB.begin(),sumB.end(),rem) - sumB.begin();
            if(highP < sumB.size()){
                minDiff = min(minDiff,abs(rem-sumB[highP]));
            }
            if(highP>0){
                minDiff = min(minDiff,abs(rem-sumB[highP-1]));
            }
        }
        return minDiff;
    }

};