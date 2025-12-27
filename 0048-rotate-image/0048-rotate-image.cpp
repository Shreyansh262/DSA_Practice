class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int j = 0;
        for (int i = 0; i < matrix.size(); i++) {
            while (j <= i) {
                swap(matrix[i][j], matrix[j][i]);
                j++;
            }
            j = 0;
        }
        for(int i = 0;i<matrix.size();i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};