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
// just write before doing it one function AND Practice of recurrsion
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

    // Mark parnt and also find the start Node 
    TreeNode *  MarkParent(TreeNode * root , unordered_map < TreeNode * ,TreeNode * > & parent_track , int start)
    {
        queue < TreeNode *  > q ; 
        q.push(root );
        TreeNode * startNode = nullptr;
        while (q.empty() == false )
        {
            TreeNode * node = q.front() ; 
            if (node -> val == start) startNode = node ; 
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
        return startNode ; 
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map < TreeNode* , TreeNode * > parent_track ; 
        unordered_map < TreeNode* , bool > visited ; 

        TreeNode * startNode = MarkParent(root , parent_track , start );

        queue < TreeNode * > q ; 
        q.push(startNode );
        visited[startNode] = true ; 
        int ans = 0 ; 
        while (q.empty() == false )
        {
            int flag = 0 ;  //  took it because , the last nodes will burn by their parent and our tree
                            // burn completely succesfully but as they burn we pushesh them in queue and to avoid that extra iteration and make our ans count ++ again : 
                            // to avoid it we will take flag  

            int size = q.size() ; 
            // ans ++ ;  //due to flag i had take it to down ( flag = if burn then increment ans)

            for (int i = 0 ; i < size ; i++ )
            {
                TreeNode * node = q.front() ; 
                q.pop() ; 

                if (node -> left && visited[node -> left ] == false )
                {
                    flag =1 ; 
                    q.push(node -> left);
                    visited[node -> left] = true ; 
                }
                if (node -> right && visited[node -> right ] == false )
                {
                    flag = 1 ;
                    q.push(node -> right );
                    visited[node -> right ] = true ; 
                }
                if (parent_track[node ] && visited[parent_track[node]] == false )
                {
                    flag = 1 ; 
                    q.push(parent_track[node]);
                    visited[parent_track[node]]=true ; 
                }
            }
            if (flag) ans ++ ;  // in lastiteration it will not incerment so in final result we will not do (return ans -1 ; )

        }
        return ans ; 
        
    }
};