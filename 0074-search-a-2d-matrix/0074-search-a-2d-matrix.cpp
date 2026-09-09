class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(),m = matrix[0].size();
        int st = 0,end = m*n-1;
        while(st<=end){
            int mid = st + (end-st)/2;
            int i = mid/m;
            int j = mid%m;
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]<target){
                st = mid+1;
            }else{
                end = mid-1;
            }
        }
        return false;
    }
};