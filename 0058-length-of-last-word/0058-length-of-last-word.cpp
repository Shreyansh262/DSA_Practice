class Solution {
public:
    int lengthOfLastWord(string s) {
        int curr = 0;
        bool reset = false;
        for(char c:s){
            if(c == ' '){
                reset = true;
            }
            else{
                if(reset){
                    curr = 0;
                    reset = false;
                }
                curr++;
            }
        }
        return curr;
    }
};