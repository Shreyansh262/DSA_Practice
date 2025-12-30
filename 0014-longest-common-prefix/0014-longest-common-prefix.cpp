class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ss = strs[0];
        for (auto x : strs) {
            while (ss.size() > 0) {
                int v = ss.size();
                x.resize(v);
                if (x == ss) break;
                else {
                    int j = v-1;
                    ss.resize(j);
                }
            }
            if (ss.size() == 0)
                return "";
        }
        return ss;
    }
};