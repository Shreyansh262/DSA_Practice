class Solution {
public:
    string removeKdigits(string num, int k) {
        string reset = ""; 
        for (char c : num) {
            while (!reset.empty() && reset.back() > c && k > 0) {
                reset.pop_back();
                k--;
            }
            if (!reset.empty() || c != '0') {
                reset.push_back(c);
            }
        }
        while (!reset.empty() && k > 0) {
            reset.pop_back();
            k--;
        }
        return reset.empty() ? "0" : reset;
    }
};