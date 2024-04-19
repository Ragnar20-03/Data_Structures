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
    int maxPath(TreeNode* root, int& path) {
        if (root == nullptr) {
            return 0;
        }

        int lh = max(0, maxPath(root->left, path)); // this is because , do no consideer negative ditance ot node values from decendants as they not give correct or maximum path 
        int rh = max(0, maxPath(root->right, path));

        path = max(path, lh + rh + root->val); // in diameter we only count nodes (1 + max(lh+rh)) but maximum path is diameter of a tree with their values 

        return root->val + max(lh, rh); // return actual node value insteat of 1 ( 1 is for node )
    }
    int maxPathSum(TreeNode* root) {
        int path = INT_MIN;
        maxPath(root, path);
        return path;
    }
};