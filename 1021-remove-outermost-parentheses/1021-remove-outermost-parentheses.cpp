class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<int> k;
        string l = "";
        for (int i = 0; i < s.size(); i++) {
            int curr;
            if (s[i] == '(') {
                if(!(k.empty()))
                l += "(";
                k.push(i);
            } else if (s[i] == ')') {
                curr = k.top();
                k.pop();
                if (!(k.empty())) {
                    l = l + ')';
                }
            }
        }
        return l;
    }
};