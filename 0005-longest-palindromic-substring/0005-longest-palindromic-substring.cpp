class Solution {
public:
    string checkEven(string s, int p) {
        string curr = "";
        int i = 0;
        while (p - i >= 0 && p + i + 1 < s.size()) {
            if (s[p - i] == s[p + i + 1])
                curr = string(1,s[p - i]) + curr + string(1,s[p + i + 1]);
            else
                break;
            i++;
        }
        return curr;
    }
    string checkOdd(string s, int p) {
        string curr = string(1,s[p]);
        int i = 1;
        while (p - i >= 0 && p + i < s.size()) {
            if (s[p - i] == s[p + i])
                curr = string(1,s[p - i]) + curr + string(1,s[p + i]);
            else
                break;
            i++;
        }
        return curr;
    }
    string longestPalindrome(string s) {
        // Optimization expand around centre
        if (s.size() == 1) return s;
        string ans;
        for (int i = 0; i < s.size(); i++) {
            string eve = checkEven(s, i);
            string odd = checkOdd(s, i);
            if (odd.size() > ans.size())
                ans = odd;
            if (eve.size() > ans.size())
                ans = eve;
        }
        return ans;
        // O(N cube) brute force - not ideal
        //  int mlen = 0;
        //  string ans;
        //  for(int i = 0;i<s.size();i++){
        //      string curr;
        //      for(int j = i;j<s.size();j++){
        //          curr += s[j];
        //          if(curr.size()<=ans.size()) continue;
        //          int x = 0,y = curr.size()-1;
        //          bool pal = true;
        //          while(x<=y){
        //              if(curr[x] != curr[y]) pal = false;
        //              x++;
        //              y--;
        //          }
        //          if(pal && curr.size()>mlen){
        //              mlen = curr.size();
        //              ans = curr;
        //          }
        //      }
        //  }
        //  return ans;
    }
};
