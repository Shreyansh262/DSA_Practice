class Solution {
public:
    bool isok(vector<int>&freq){
        for(int i : freq){
            if(i>2) return false;
        }
        return true;
    }
    int maximumLengthSubstring(string s) {
        vector<int>freq(26,0);
        int i,j;
        i = j = 0;
        int len = 0,maxlen = 0;
        for(int j = 0;j<s.size();j++){
            freq[s[j]-'a']++;
            while(!isok(freq)){
                freq[s[i++]-'a']--;
            }
            len = j-i+1;
            maxlen = max(maxlen,len);

        }
        return maxlen;
    }
};