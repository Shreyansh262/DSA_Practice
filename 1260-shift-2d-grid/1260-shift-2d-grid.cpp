class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int t = (k/n)%m;
        int u = k%n;
        vector<int>st;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                st.push_back(grid[i][j]);
            }
        }
        int ind = st.size() - t * n - u;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                grid[i][j] = st[ind%st.size()];
                ind++;
            }
        }
        return grid;
    }
};