class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int sum = 0;
        int A = 0,B = 0;
        vector<int> st;
        for(int i = 0;i<tokens.size();i++){
            if(tokens[i] == "/"||tokens[i] == "*"||tokens[i] == "-"||tokens[i] == "+"){
                A = st[st.size()-1];
                st.pop_back();
                B = st[st.size()-1];
                st.pop_back();
                if (tokens[i] == "+"){
                    sum = A+B;
                }
                else if (tokens[i] == "-"){
                    sum = B-A;
                }
                else if (tokens[i] == "*"){
                    sum = A*B;
                }
                else{
                    sum = (int)(B/A);
                }
                st.push_back(sum);
            }
            else{
                st.push_back(stoi(tokens[i]));
            }
        }
        sum = st[0];
        return sum;
    }
};