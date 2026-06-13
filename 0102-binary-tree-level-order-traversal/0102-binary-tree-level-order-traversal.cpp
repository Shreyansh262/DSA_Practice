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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> store;
        store.push(root);
        while(!store.empty()){
            int sz = store.size();
            vector<int> ll;
            for(int i = 0;i<sz;i++){
                TreeNode* node = store.front();
                store.pop();
                if(node->left != nullptr) store.push(node->left);
                if(node->right != nullptr) store.push(node->right);
                ll.push_back(node->val);
            }
            ans.push_back(ll);
        }
        return ans;
    }
};