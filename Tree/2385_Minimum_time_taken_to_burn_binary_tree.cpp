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
    TreeNode * findStart (TreeNode * root , int start)
    {
        if (root == nullptr)return nullptr;
        if (root -> val == start ) return root ; 
        TreeNode * left = findStart(root -> left , start);
        if (left != nullptr)
        {
            return left; 
        }
        TreeNode * right = findStart(root -> right , start);
        if (right != nullptr)
        {
            return right; 
        }
        return nullptr ; 
    }
    void MarkParent(TreeNode * root , unordered_map < TreeNode * ,TreeNode * > & parent_track)
    {
        queue < TreeNode *  > q ; 
        q.push(root );

        while (q.empty() == false )
        {
            TreeNode * node = q.front() ; 
            q.pop() ; 
            if (node -> left)
            {
                q.push(node ->left);
                parent_track[node -> left] = node ; 
            }
            if (node -> right)
            {
                q.push(node ->right);
                parent_track[node -> right] = node ; 
            }
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map < TreeNode* , TreeNode * > parent_track ; 
        unordered_map < TreeNode* , bool > visited ; 
        MarkParent(root , parent_track);
        TreeNode * startNode = findStart(root , start);

        queue < TreeNode * > q ; 
        q.push(startNode );
        visited[startNode] = true ; 
        int ans = 0 ; 
        while (q.empty() == false )
        {
            int size = q.size() ; 
            ans ++ ; 

            for (int i = 0 ; i < size ; i++ )
            {
                TreeNode * node = q.front() ; 
                q.pop() ; 

                if (node -> left && visited[node -> left ] == false )
                {
                    q.push(node -> left);
                    visited[node -> left] = true ; 
                }
                if (node -> right && visited[node -> right ] == false )
                {
                    q.push(node -> right );
                    visited[node -> right ] = true ; 
                }
                if (parent_track[node ] && visited[parent_track[node]] == false )
                {
                    q.push(parent_track[node]);
                    visited[parent_track[node]]=true ; 
                }
            }
        }
        return ans -1  ; 
        
    }
};