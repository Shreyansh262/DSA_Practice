class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> ss, st;
        if (s.size() != t.size())
            return false;
        for (int i = 0; i < s.size(); i++) {
            ss[s[i]]++;
            st[t[i]]++;
        }
        for (char k = 'a'; k <= 'z'; k++) {
            if (ss[k] != st[k]) {
                return false;
            }
        }
        return true;
    }
};