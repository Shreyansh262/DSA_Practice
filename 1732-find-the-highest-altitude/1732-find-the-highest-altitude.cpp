class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int alt = 0,maxalt =0;
        for(int i : gain){
            alt = alt+i;
            maxalt = max(maxalt,alt);
        }
        return maxalt;
    }
};