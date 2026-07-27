/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root,int& maxSum){
        if(!root){
            return 0;
        }
        int lSum = solve(root->left,maxSum);
        int rSum = solve(root->right,maxSum);
        lSum = (lSum>0)?lSum:0;
        rSum = (rSum>0)?rSum:0;
        maxSum = max(maxSum,root->val+lSum+rSum);
        return root->val+max(lSum,rSum);
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        solve(root,maxSum);
        return maxSum;
    }
};