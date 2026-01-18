class Solution {
public:
    bool isValid(string s) {
        stack<char> container;
        for (char x : s) {
            if (x == '(' || x == '{' || x == '[') {
                container.push(x);
            } else if (!container.empty()) {
                if (x == ')' && container.top() == '(') {
                    container.pop();
                } else if (x == '}' && container.top() == '{') {
                    container.pop();
                } else if (x == ']' && container.top() == '[') {
                    container.pop();
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
        if (container.empty()) {
            return true;
        }
        return false;
    }
};