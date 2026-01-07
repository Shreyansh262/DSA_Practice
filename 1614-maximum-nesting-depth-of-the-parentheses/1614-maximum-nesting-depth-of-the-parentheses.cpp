class Solution {
public:
    int maxDepth(string s) {
        int dp = 0,maxdp = 0;
        for(char &i : s){
            if(i=='('){
                dp++;
                maxdp = max(maxdp,dp);
            }
            else if(i==')'){
                dp--;
            }
        }
        return maxdp;
    }
};