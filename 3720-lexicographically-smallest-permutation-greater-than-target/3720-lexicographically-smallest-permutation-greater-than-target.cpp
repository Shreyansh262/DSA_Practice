class Solution {
public:
    string solve(int len, vector<int>& freq, string tar) {
        string s = "";
        char st = tar.empty() ? 'a' - 1 : tar[0];
        bool ok = false;
        for (char c = st + 1; c <= 'z'; c++) {
            if (freq[c - 'a'] != 0) {
                freq[c - 'a']--;
                s.push_back(c);
                ok = true;
                break;
            }
        }
        if (!ok)
            return "..";
        for (char c = 'a'; c <= 'z'; c++) {
            if (freq[c - 'a'] != 0) {
                string x = string(freq[c - 'a'], c);
                freq[c - 'a'] = 0;
                s.append(x);
            }
        }
        return s;
    }
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        for (int i = n - 1; i >= 0; i--) {
            vector<int> tempFreq = freq;
            bool validPrefix = true;
            string currentAns = "";
            for (int j = 0; j < i; j++) {
                if (tempFreq[target[j] - 'a'] == 0) {
                    validPrefix = false;
                    break;
                }
                tempFreq[target[j] - 'a']--;
                currentAns.push_back(target[j]);
            }
            if (!validPrefix) continue;
            string suffix = solve(n - i, tempFreq, target.substr(i));
            if (suffix != "..") {
                return currentAns + suffix;
            }
        }
        return "";
    }
};