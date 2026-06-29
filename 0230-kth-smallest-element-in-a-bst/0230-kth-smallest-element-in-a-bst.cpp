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
    int fn(TreeNode* root,vector<int>& ans){
        if(root == nullptr) return 0;
        int x = fn(root->left,ans);
        ans.push_back(root->val);
        int y = fn(root->right,ans);
        return 0;
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>ans;
        int x = fn(root,ans);
        return ans[k-1];
    }
};