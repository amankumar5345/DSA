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
    int minDepth(TreeNode* root) {
        if(!root)
        return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        while(!q.empty()){
            auto [root, depth] = q.front();
            q.pop();
            if (!root->left && !root->right)
            return depth;
            if (root -> left)
            q.push ({root->left, depth+1});
            if (root -> right)
            q.push ({root -> right, depth+1});
        }
        return 0;
    }
};