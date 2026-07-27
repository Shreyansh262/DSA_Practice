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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> bfs;
        bfs.push(root);
        vector<int> rsv;
        while (!bfs.empty()) {
            int sz = bfs.size();
            bool lc = true;
            for (int i = 0; i < sz; i++) {
                TreeNode* temp = bfs.front();
                bfs.pop();
                if (lc) {
                    rsv.push_back(temp->val);
                    lc = !lc;
                }
                if (temp->right)
                    bfs.push(temp->right);
                if (temp->left)
                    bfs.push(temp->left);
            }
            lc = !lc;
        }
        return rsv;

    }
};