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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue < pair < TreeNode * , pair < int , int > > > q ; 
        map < int , map < int , multiset< int > > > m ; 
        vector<vector<int > >ans ; 
        if (root == nullptr)
        {
            return ans ; 
        }
        q.push({root , { 0 , 0 } });

        while (q.empty() == false )
        {
            TreeNode * node = q.front() . first ; 
            int x = q.front().second.first ; 
            int y = q.front() . second.second ; 
            q.pop() ; 

            m[x][y].insert(node -> val);

            if (node -> left ) q.push({node -> left , { x-1 , y + 1 }});
            if (node -> right ) q.push({node -> right , { x+ 1 , y + 1 }});
        }

        for (auto it : m )
        {
            vector<int > col ; 
            for (auto it2 : it.second)
            {
                for (auto it3 : it2.second)
                {
                    col.push_back(it3);
                }
            }
            ans.push_back(col);
        }
          return ans ; 
    }
};