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
bool isLeaf (TreeNode * root ) 
{
    if (root -> left == nullptr && root -> right == nullptr )
    {
        return true ; 
    } 
    return false ; 
}

bool helper (TreeNode * root , int & sum  ,  int & target ) 
{
    if (root == nullptr)
    {
        return false ; 
    }
    cout<<"current node is : "<<root -> val ; 
    sum += root -> val ; 
    cout<<"sum is : "<<sum <<endl;
    if (isLeaf(root  ))
    {
        if (sum == target) 
        {
            return true ; 
        }
    }
    if (helper(root -> left  , sum , target) == true)
    {
        return true ; 
    }
    if ( helper(root  -> right , sum , target) == true )
    {
        return true ; 
    }
    sum = sum -  root -> val ; 
    return false ; 
}

    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0 ; 
        return helper ( root , sum , targetSum);
    }
};