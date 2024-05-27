class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) { 
        
        // step , node , dist 
        vector<pair < int ,  int >  > adj [ n ];
        for (int i = 0 ; i < flights.size() ; i++ )
        {
            adj[flights[i][0]].push_back({flights[i][1] , flights[i][2]});
        }

        vector<int > distance ( n  , INT_MAX);
        distance[src] = 0 ; 
        queue < pair < int ,  pair < int , int > >  > q ; 
        q.push({0 , {src , 0 } });
        while (q.empty() == false )
        {
            int step = q.front().first ; 
            int node = q.front().second.first ; 
            int dist = q.front().second.second ; 
            q.pop();

            if (step > k )continue ; 

            for (auto it : adj[node])
            {
                int adjNode = it.first ; 
                int weight = it.second ; 
                if (dist + weight < distance[adjNode]  && step <= k )
                {
                    distance[adjNode] = dist + weight ; 
                    q.push( { step + 1 , {adjNode , distance[adjNode] }});
                }
            }
        }
        if (distance[dst] == INT_MAX)return -1 ; 
        return distance[dst];
    }
};