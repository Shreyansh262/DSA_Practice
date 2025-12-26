class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set <int> ip,jp;
        for(int i = 0;i<matrix.size();i++){
            for(int j = 0;j<matrix[0].size();j++){
                if(matrix[i][j] == 0){
                    ip.insert(i);
                    jp.insert(j);
                }
            }
        }
        for(int i = 0;i<matrix.size();i++){
            for(int j = 0;j<matrix[0].size();j++){
                if(ip.find(i) != ip.end() || jp.find(j) != jp.end()){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};