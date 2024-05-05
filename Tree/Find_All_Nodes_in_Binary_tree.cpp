

//  This is regural approach to count all nodes
int countNodes(BinaryTreeNode<int> *root) {
  // Write your code here.
  if (root == nullptr)return 0 ; 

        // int left_height = findLeftHeight(root);
        // int right_height = findRightHeight(root);

        // if (left_height == right_height )return (1 << right_height ) -1 ; // (1 << right_height) is equivalent to raising 2 to the power of right_height.


  return 1 + countNodes(root -> left) + countNodes(root -> right);
}

//  Optiaml Approach without traversing all the nodes 
//  by using the (2 ^ height ) -1 formula as it is complete binary tree 
//  it works only when the both lh and rh have equal heights 
// other wise simply traverse all the nodes 

class Solution {
public:
    int findRightHeight(TreeNode * root )
    {
        if (root == nullptr )return 0;
        return 1 + findRightHeight(root -> right);
    }
      int findLeftHeight(TreeNode * root )
    {
        if (root == nullptr )return 0;
        return 1 + findLeftHeight(root -> left);
    }
    int countNodes(TreeNode* root) {
        if (root == nullptr)return 0 ; 
        int left_height = findLeftHeight(root);
        int right_height = findRightHeight(root);

        if (left_height == right_height )return (1 << right_height ) -1 ; // (1 << right_height) is equivalent to raising 2 to the power of right_height.

        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
};
