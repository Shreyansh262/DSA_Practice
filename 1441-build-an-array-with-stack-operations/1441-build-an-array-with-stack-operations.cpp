class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        vector<int> stream;
        for(int i = 0; i<n;i++){
            stream.push_back((i+1));
        }
        int i = 0,j=0;
        while(i<n){
            if(j ==(target.size())){
                break;
            }
            ans.push_back("Push");
            if(stream[i]==target[j]){
                i++;
                j++;
            }
            else{
                ans.push_back("Pop");
                i++;
            }

        }
        return ans;
    }
};