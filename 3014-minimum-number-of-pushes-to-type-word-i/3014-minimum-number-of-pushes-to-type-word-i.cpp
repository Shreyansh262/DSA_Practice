class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26,0);
        for(char c : word){
            freq[c-'a']++;
        }
        sort(freq.rbegin(),freq.rend());
        int num=0,ct=1;
        int ans = 0;
        for(int i :freq){
            num++;
            if(num>8){
                ct++;
                num = 1;
            }
            ans += i*ct;
        }
        return ans;

    }
};