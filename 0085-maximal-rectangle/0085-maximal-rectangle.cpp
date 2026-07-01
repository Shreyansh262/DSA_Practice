class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();
        for (int i = 0; i <= n; i++) {
            int currHeight = (i == n ? 0 : heights[i]);
            while (!st.empty() && currHeight < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();
                int width;
                if (st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;
                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix[0].size();
        vector<int>heights(m,0);
        int maxArea = 0;
        for(auto it : matrix){
            for(int i = 0;i<m;i++){
                if(it[i]=='1'){
                    heights[i]++;
                }
                else{
                    heights[i]=0;
                }
            }
            int rowArea = largestRectangleArea(heights);
            maxArea = max(maxArea,rowArea);
        }
        return maxArea;


    }
};