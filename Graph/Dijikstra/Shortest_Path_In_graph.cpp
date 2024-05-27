//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        priority_queue < pair < int , int > , vector<pair < int , int > > ,
                        greater<pair<int , int > > > pq ; 
                        
        vector<pair<int , int  > >  adj [n + 1 ];
        
        for (int i = 0 ; i < m ; i++ )
        {
            adj[edges[i][0]].push_back({edges[i][1] , edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0] , edges[i][2]});
        }
        vector<int > distance ( n + 1 , 1e9);
        vector<int > parent ( n + 1 );
        for (int i = 0 ; i <= n ; i++)
        {
            parent [ i ] = i ; 
        }
        
        pq.push({0 , 1 }); 
        distance[1] = 0 ; 
        
        while (!pq.empty() )
        {
            int node = pq.top().second ; 
            int dist =  pq.top().first ; 
            pq.pop() ; 
            
            for (auto it : adj [ node])
            {
                int adjNode = it.first;
                int edge = it.second ; 
                
                if (dist + edge < distance[adjNode])
                {
                    distance[adjNode] = dist + edge ; 
                    pq.push({distance[adjNode] , adjNode});
                    parent[adjNode] = node ; 
                }
                
            }
        }
        
        if (distance[n] == 1e9) return {-1} ; 
        
        vector<int > path ; 
        int node = n ; 
        while (parent[node] != node)
        {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        path.push_back(distance[n]);
        reverse(path.begin() , path.end());
        return path ; 
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
    }
}

// } Driver Code Ends