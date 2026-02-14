class Solution {
public:
    int longestBalanced(string s) {
        int maxl = 0;
        for (int i = 0; i < s.size(); i++) {
            unordered_map<char,int> f;
            int maxf = 0;
            for (int j = i; j < s.size(); j++) {
                f[s[j]]++;
                maxf = max(maxf, f[s[j]]);
                if ((j - i + 1) / f.size() == maxf) {
                    maxl = max(maxl, j - i + 1);
                }
            }
        }
        return maxl;
    }
};