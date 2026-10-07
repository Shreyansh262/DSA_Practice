class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int>freq;
        int m = 0;
        int j = 0;
        int maxAns = 0;
        for(int i = 0;i<fruits.size();i++){
            if(freq[fruits[i]]==0){
                m++;
            }
            freq[fruits[i]]++;
            if(m<=2){
                maxAns = max(maxAns,i-j+1);
            }
            else{
                while(m>2){
                    freq[fruits[j]]--;
                    if(freq[fruits[j]]==0){
                        m--;
                    }
                    j++;
                }
            }
        }
        return maxAns;
    }
};