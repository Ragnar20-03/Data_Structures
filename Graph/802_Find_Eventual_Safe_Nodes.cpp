/*  Approach : 
    first reverse all the nodes ( graph )
    then find terminal node 
    and do BFSKahsansAlgo for toposort and push it in queue 
    sort it and return it 
*/
#include <vector> 
class Solution {
    private : 
    bool dfs(int start , int visited [] , int path [] ,  int check [] , vector<int > adj[] )
    {
        visited[start] = 1 ;    
        path[start] = 1  ; 

        for (auto it : adj[start])
        {
            if (visited[it] != 1 )
            {
                if (dfs(it, visited , path , check , adj ) == true ) // cycle is detected 
                {
                    return true ; 
                }
            }
            else if (path[start] == 1 )  //cycle is detected 
            {
                return true ;
            }
        }
        check[start] = 1 ; // node is safe that doesnt contain cycle 
        path[start] = 0 ; // remove path visited as there can be another path for differnt traversal 
        return false ;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // BFS KAhans Solution 
        int n = graph.size() ; 
        int indegree[10000] = { 0 } ; 
        vector<int > ans ; // array of safe nodes 
        queue < int > q ;   
        vector<int > adjRev [10000] ; 

        for (int i = 0 ; i < n ; i ++ )
        {
            for (auto it : graph [ i ])
            {
                adjRev[it].push_back(i);
                indegree[i] ++ ; 
            }
        }
        for (int i = 0 ; i < n ; i++ )
        {
            if (indegree[i] == 0 )
            {
                q.push(i);
            }
        }
        while (q.empty() == false ) 
        {
            int node = q.front() ; 
            ans.push_back(node ); 
            q.pop() ;

            for (auto it : adjRev[node])
            {
                indegree[it] -- ; 
                if (indegree[it] == 0 )
                {
                    q.push(it);
                }
            }
        }
        sort (ans.begin() , ans.end() ) ;
        return ans ; // safe nodes 
    }
};