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
    vector<TreeNode*> buildTrees(int start, int end) {
        vector <TreeNode*> trees;

        if(start > end){
            trees.push_back(nullptr);
            return trees;
        }

        for (int i = start; i <= end; i++){
            vector<TreeNode*> leftTrees = buildTrees(start, i - 1);
            vector<TreeNode*> rightTrees = buildTrees(i+1, end);
            for(TreeNode* left : leftTrees){
                for(TreeNode* right : rightTrees){
                    TreeNode* root = new TreeNode(i);
                    root -> left = left;
                    root -> right = right;
                    trees.push_back(root);
                }
            }
        }
        return trees;
    }
    vector<TreeNode*> generateTrees (int n){
        if (n == 0)
        return {};
        return buildTrees(1, n);
    }
};