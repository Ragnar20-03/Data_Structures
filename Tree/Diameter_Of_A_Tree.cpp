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
    int diameterOfATree(TreeNode * root , int &max_Diameter)
    {
        if (root == nullptr)
        {
            return 0 ; 
        }
        int lh = diameterOfATree(root -> left , max_Diameter);
        int rh = diameterOfATree(root -> right,max_Diameter);

        max_Diameter = max((lh+rh) , max_Diameter);
        return max(lh , rh ) + 1 ; 
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int max = 0 ; 
        diameterOfATree(root , max);
        return max ; 
    }
};