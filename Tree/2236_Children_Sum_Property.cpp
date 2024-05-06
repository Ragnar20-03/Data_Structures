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
    bool isLeaf ( TreeNode * root )
    {
        return root -> left == nullptr && root -> right == nullptr ; 
    }

    bool checkTree(TreeNode* root) {
        queue < TreeNode * > q ; 
        if (!root)return false ; 
        int sum = 0 ; 

        q.push(root);
        while (q.empty () == false )
        {
            TreeNode * node = q.front();
            q.pop() ; 

            if (node -> left)
            {
                if (isLeaf(node -> left) == false )
                {
                    q.push(node -> left);
                }
                sum += node -> left ->  val ; 
            }
            if (node -> right)
            {
                if (isLeaf(node -> right) == false )
                {
                    q.push(node -> left);
                }
                sum += node ->right ->  val ; 
            }

            if (sum != node -> val )
            {
                return false ; 
            }
        }
        return true ; 
    }
};