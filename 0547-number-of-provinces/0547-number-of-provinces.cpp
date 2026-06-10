class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> isVisited(n, 0);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (isVisited[i] == 1)
                continue;
            else {
                isVisited[i] = 1;
                isVisit(isConnected, isVisited,n, i);
                count++;
            }
        }
        return count;
    }
    void isVisit(vector<vector<int>>& isConnected, vector<int>& isVisited,int n, int i) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;
            else if (isConnected[i][j] == 0)
                continue;
            else if (isVisited[j] == 1)
                continue;
            else{
                isVisited[j] = 1;
                
                isVisit(isConnected,isVisited,n,j);}
        }
    }
};