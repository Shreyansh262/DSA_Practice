class Solution {
public:
    string reorderSpaces(string text) {
        int space = 0;
        int word = 0;
        bool x = false;
        vector<string>all;
        string z="";
        for(char c:text){
            if(c==' '){
                space++;
                x = false;
                if(z!="") all.push_back(z);
                z="";
            }
            else{
                z+=c;
                if(!x){
                    x = true;
                    word++;
                }
            }
        }
        if(z!="") all.push_back(z);
        if(space == 0) return text;
        else if(word == 1) return all[0]+string(space,' ');
        int evesp = space/(word-1);
        int extra = space%(word-1);
        word = 0;
        string ans = "";
        for(int i = 0;i<all.size();i++){
            ans+=all[i];
            if(i!=all.size()-1){
                ans+=string(evesp,' ');
            }else{
                ans+=string(extra,' ');
            }
        }
        return ans;
    }
};