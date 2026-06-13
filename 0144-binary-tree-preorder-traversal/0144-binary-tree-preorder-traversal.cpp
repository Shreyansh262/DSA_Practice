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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        int x = fn(root,ans);
        return ans;
        
    }
    int fn(TreeNode* root,vector<int>& ans){
        if(root == nullptr) return 0;
        ans.push_back(root->val);
        int x = fn(root->left,ans);
        int y = fn(root->right,ans);
        return 0;
    }
};