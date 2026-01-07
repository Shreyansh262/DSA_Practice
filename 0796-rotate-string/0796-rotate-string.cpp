class Solution {
public:
    bool rotateString(string s, string goal) {
        //Brute force
        // if(s.size()!= goal.size()) return false;
        // if(s==goal) return true;
        // for(int i = 1;i<s.size();i++){
        //     bool pos = true;
        //     for(int k = 0;k<s.size();k++){
        //         if(s[k] != goal[((k+i)%s.size())]){
        //             pos = false;
        //             break;
        //         }
        //     }
        //     if(pos) return true;
        // }
        // return false;
        //Optimization
        if(s.size()!= goal.size()) return false;
        if(s==goal) return true;
        string doubledS = s + s;
        return doubledS.find(goal) != string::npos;
    }
};