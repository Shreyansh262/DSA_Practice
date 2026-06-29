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
int count = 0;
    int result = -1;
    void fn(TreeNode* root,int k){
        if(root == nullptr||count>=k) return ;
        fn(root->left,k);
        count++;
        if(count==k){
            result = root->val;
            return;
        }
        fn(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        fn(root,k);
        return result;
    }
};