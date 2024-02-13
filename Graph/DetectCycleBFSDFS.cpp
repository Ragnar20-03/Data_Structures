//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private : 
    bool detectCycleDFS(int src , int parent, int visited [] , vector<int> adj [] )
    {
        visited[src] = 1 ; 
        for (auto it : adj[src])
        {
            if (visited[it] == 0 )
            {
                if(detectCycleDFS(it , src , visited, adj) == true)
                {
                    return true ; 
                }
            }
            // else if (it != parent)
            else if (visited[it] == 1 && it != parent) // it is visited and not coming from parent
            {
                return true ; 
            }
        }
        return false ; 
    }
    bool detectCycle(int src , int visited[] , vector<int > adj[])
    {
        visited[src] = 1; 
        queue<pair<int , int > > q; 
        q.push({src , -1 }); 
        
        while (q.empty() == false )
        {
            int src = q.front().first ;
            int parent = q.front().second ; 
            q.pop() ; 
            
            for (auto it : adj[src])
            {
                if (visited[it] != 1 )
                {
                    visited[it] = 1 ; 
                    q.push({ it , src});
                }
                else if (visited[it] == 1 && it != parent)
                {
                    return true ; 
                }
            }
        }
        return false ; 
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int visited[V] = { 0 }  ; 
         bool bFlag = false ; 
        for (int i = 0 ; i < V ; i ++  )
        {
            if (visited[i] != 1 )
            {
                 if (detectCycleDFS(i , -1  , visited , adj   ) == true)
                 {
                     return true ; 
                 }
            }
        }
        return false ; 
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends