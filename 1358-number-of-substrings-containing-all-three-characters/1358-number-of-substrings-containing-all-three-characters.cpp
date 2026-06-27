class Solution {
public:
    int findj(queue<int>& apos,queue<int>& bpos,queue<int>& cpos){
        int x = apos.front(),y=bpos.front(),z=cpos.front();
        if(x>y&&x>z) return x;
        else if(y>x&&y>z) return y;
        else return z;
    }
    void remi(queue<int>& a,queue<int>& b,queue<int>& c){
        if(a.front()<b.front()&&a.front()<c.front()) a.pop();
        else if(a.front()>b.front()&&b.front()<c.front()) b.pop();
        else c.pop();
    }
    int numberOfSubstrings(string s) {
        int i=0,j=0,sum = 0;
        queue<int>apos,bpos,cpos;
        for(int c =0;c<s.size();c++){
            if(s[c] =='a')apos.push(c);
            if(s[c] =='b')bpos.push(c);
            if(s[c] =='c')cpos.push(c);
        }
        if(apos.size()==0||bpos.size()==0||cpos.size()==0) return 0;
        while(apos.size()!=0&&bpos.size()!=0&&cpos.size()!=0){
            int x = findj(apos,bpos,cpos);
            sum += s.size()-x;
            remi(apos,bpos,cpos);
        }
        return sum;
    }
};