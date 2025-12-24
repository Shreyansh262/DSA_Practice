class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set <int> sequence;
        for(int i :nums){
            sequence.insert(i);
        }
        int count = 1,maxc = 1, prev = *sequence.begin();
        for(auto i = sequence.begin();i!=sequence.end();i++){
            if(*i - prev == 1){
                count ++;
                maxc = max(maxc,count);
            }
            else{
                count = 1;
            }
            prev = *i;
        }
        if(nums.size()==0){
            return 0;
        }
        return maxc;
    }
};