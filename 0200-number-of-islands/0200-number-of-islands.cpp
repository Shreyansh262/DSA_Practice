class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>isVis(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        int cnt = 0;
        vector<int>drow = {-1,0,1,0};
        vector<int>dcol = {0,1,0,-1};
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(isVis[i][j] || grid[i][j]=='0') continue;
                isVis[i][j] = 1;
                if(grid[i][j]=='1') q.push({i,j});
                while(!q.empty()){
                    auto it = q.front();
                    q.pop();
                    int nr = it.first;
                    int nc = it.second;
                    for(int k = 0;k<4;k++){
                        int r = nr + drow[k];
                        int c = nc + dcol[k];
                        if(r>=0&&r<m&&c>=0&&c<n&&!isVis[r][c]&&grid[r][c]=='1'){
                            q.push({r,c});
                            isVis[r][c] = 1;
                        }
                    }
                }
                cnt++;
            }
        }
        return cnt;
    }
};