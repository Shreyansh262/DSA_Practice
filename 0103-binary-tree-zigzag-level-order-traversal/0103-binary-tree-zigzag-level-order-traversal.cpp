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
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
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
        return ans.size();
    }
    void solve(TreeNode* root,int height,vector<vector<int>>&ziggy){

        if(!root) return;
        ziggy[height-1].push_back(root->val);
        solve(root->left,height+1,ziggy);
        solve(root->right,height+1,ziggy);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int n = maxDepth(root);
        vector<vector<int>>ziggy(n,vector<int>());
        solve(root,1,ziggy);
        for(int i = 0;i<ziggy.size();i++){
            if(i&1){
                reverse(ziggy[i].begin(),ziggy[i].end());
            }
        }
        return ziggy;
    }
};