/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <unordered_map>
class Solution {
    private : 

    // This is for marking which node has which parent
    void MarkParent (TreeNode * root , unordered_map < TreeNode * , TreeNode * > & parent_track)
    {
        queue < TreeNode * > q ; 
        q.push(root);

        while (q.empty() == false )
        {
            TreeNode * current = q.front();
            q.pop() ; 
            if (current -> left )
            {
                parent_track[current->left] = current ; 
                q.push(current -> left);
            }
            if (current -> right )
            {
                parent_track[current->right] = current ; 
                q.push(current -> right);
            }
        }

    }
public:

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int > ans ; 
        unordered_map < TreeNode * , TreeNode * > parent_track  ; 
        unordered_map < TreeNode * , bool > visited ; 

        MarkParent( root , parent_track);

        queue < TreeNode * > q ; 
        q.push(target) ;
        visited[target] = true ;  
        int distance = 0 ; 

        while (q.empty() == false )
        {
            if (distance ++  == k )break ;  // first check then increment 
            int size = q.size() ; 
            for (int i = 0 ; i < size ; i++ )
            {
                TreeNode * node = q.front() ;
                q.pop() ; 

                if (node -> left && !visited[node -> left])
                {
                    q.push(node -> left);
                    visited [ node -> left] = true ;
                }
                if (node -> right && !visited[node -> right])
                {
                    q.push(node -> right);
                    visited [ node -> right] = true ;
                }
                if (parent_track[node ] && !visited[parent_track[node ]])
                {
                    q.push(parent_track[node]);
                    visited[parent_track[node]] = true ; 
                }
            }
        }


        while (q.empty() == false )
        {
            TreeNode * node = q.front() ; q.pop() ; 
            ans.push_back(node -> val );
        }
        return ans ; 
    }
};

/*
    Algorithm : 
    mark parent 
    push the target node to queue and make it visited ; 
    while q.empty () == false :
        take node from q ; 
        //////////////////////////////////////////
        if distance == k (steps)break the loop 
        //////////////////////////////////////////
        check left , right , parent of that node from parent_track_map AND All of them are not visited if so then push it  

    coppy remaining itemd from q and push it into ans vector
    return ans ; 

*/