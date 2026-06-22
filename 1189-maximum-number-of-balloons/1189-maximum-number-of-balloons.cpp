class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map <char,int> bal = {{'b',0},{'a',0},{'l',0},{'o',0},{'n',0}};
        for(char o : text){
            if(bal.find(o)!=bal.end()){
                bal[o]++;
            }
        }
        bal['l'] = bal['l']/2;
        bal['o'] = bal['o']/2;
        int ans = INT_MAX;
        for(auto it : bal){
            ans = min(ans,it.second);
        }
        return ans;
    }
};