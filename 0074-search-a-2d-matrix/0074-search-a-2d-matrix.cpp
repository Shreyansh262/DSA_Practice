class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int st = 0,end = matrix.size()-1;
        int sti = 0, endi = matrix[0].size()-1;
        while(st<=end){
            int mid = end -(end-st)/2;
            int sti = 0, endi = matrix[0].size()-1;
            if(matrix[mid][sti]<=target && matrix[mid][endi]>= target){
                while(sti<=endi){
                    int midi = endi-(endi-sti)/2;
                    if(matrix[mid][midi]==target) return true;
                    else if(matrix[mid][midi]>=target) endi = midi-1;
                    else sti = midi+1;
                }
                return false;
            }
            else if(matrix[mid][sti]>=target) end = mid -1;
            else st = mid +1;
        }
        return false;
    }
};