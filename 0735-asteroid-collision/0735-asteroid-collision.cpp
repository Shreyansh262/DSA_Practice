class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> stk;
        bool dest = false;
        for (int i = 0; i < ast.size(); i++) {
            dest = false;
            if (stk.empty() || ast[i] > 0 || stk.top() < 0) {
                stk.push(ast[i]);
            } else {
                while (!stk.empty() && stk.top() > 0 &&
                       stk.top() <= ast[i] * (-1)) {
                    if (stk.top() == ast[i] * (-1)) {
                        stk.pop();
                        dest = true;
                        break;
                    }
                    stk.pop();
                }
                if (!dest) {
                    if (stk.empty() || stk.top() < 0) {
                        stk.push(ast[i]);
                    }
                }
            }
        }
        vector<int> v;
        while (!stk.empty()) {
            v.push_back(stk.top());
            stk.pop();
        }
        reverse(v.begin(), v.end());

        return v;
    }
};