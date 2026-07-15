class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int>> grid(m,vector<int>(n,0));
        vector<int> row(m);
        vector<int> col(n);
        for(auto it:indices){
            row[it[0]]++;
            col[it[1]]++;
        }
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                grid[i][j] += row[i]+col[j];
            }
        }
        int ans = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]&1) ans++;
            }
        }
        return ans;
    }
};