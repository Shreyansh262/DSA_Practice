/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        queue<TreeNode*> intest;
        intest.push(root);
        int ans = 0;
        while (!intest.empty()) {
            int sz = intest.size();
            for (int i = 0; i < sz; i++) {
                TreeNode* temp = intest.front();
                intest.pop();
                if(temp->left){
                    if(!(temp->val&1)){
                        if(temp->left->left){
                            ans+=temp->left->left->val;
                        }
                        if(temp->left->right){
                            ans+=temp->left->right->val;
                        }
                        
                    }
                    intest.push(temp->left);
                }
                if(temp->right){
                    if(!(temp->val&1)){
                        if(temp->right->left){
                            ans+=temp->right->left->val;
                        }
                        if(temp->right->right){
                            ans+=temp->right->right->val;
                        }
                        
                    }
                    intest.push(temp->right);
                }
            }
        }
        return ans;
    }
};