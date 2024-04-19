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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int > > ans ; 
        if (root == nullptr) return ans ; 
        vector<int > temp ; 
        bool flag = true ; 
        queue < TreeNode *  > q ; 
        q.push(root );

        while (q.empty() == false)
        {
            int size = q.size() ; 
            vector<int > level (size); 
            for (int i = 0 ; i < size ; i++ )
            {
                TreeNode * node = q.front() ; 
                q.pop() ; 

        // THis part is new  : 1 just declare the vector size because  if flag is false , means it is ( R -> L) , we have to push it from back  
                int index = flag ? i : (size - 1 - i) ; 
                
                level[index] = node -> val ;

                if (node -> left != nullptr) q.push(node -> left);
                if (node -> right != nullptr) q.push(node -> right);
            }
            flag = !flag; // reverse the flag
            ans.push_back(level);
        }
        return ans ; 
    }
};