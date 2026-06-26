class Solution {
public:
    int minMaxDifference(int num) {
        stack<int> x,y;
        if(num == 0){
            return 9;
        }
        int n = num;
        while(num>0){
            int z = num%10;
            x.push(z);
            num/=10;
        }
        y = x;
        int currm = x.top();
        int currM = -1;
        int n1 = 0;
        while(!x.empty()){
            if(x.top()==currm){
                n1 = n1*10;
            } else {
                n1 = n1*10 + x.top();
            }
            if(currM == -1 && x.top()!=9){
                currM = x.top();
            }
            x.pop();
        }
        int n2 = 0;
        if (currM == -1) return n- n1;
        while(!y.empty()){
            if(y.top()==currM){
                n2 = n2*10 + 9;
            } else {
                n2 = n2*10 + y.top();
            }
            y.pop();
        }
        return n2 - n1;

    }
};