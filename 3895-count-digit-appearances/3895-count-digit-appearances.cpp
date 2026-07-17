class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        string s;
        for(int i : nums){
            string t = to_string(i);
            s=s+t;
        }
        int count = 0;
        for(char c:s){
            if((c-'0') == digit) count++;
        }
        return count;
    }
};