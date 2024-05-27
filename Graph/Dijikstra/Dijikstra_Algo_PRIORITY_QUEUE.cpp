     #include<iostream>
        using namespace  std ; 
        
     #include<vector>
     #include<set>
#include <queue>
     // Dijkstra USING PRiority QUEUE ;    
   vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue < pair<int , int > , vector<pair<int , int > > , 
                        greater<pair<int , int > > > pq ; 
                        
        pq.push({S , 0});
        vector<int > distance ( V , INT_MAX) ; 
        distance[S] = 0 ; 
        
        while (!pq.empty())
        {
            auto it = pq.top();
            int dist = it.first ; 
            int node = it.second ; 
            pq.pop() ;
            
            for ( auto it : adj [node])
            {
                int adjNode = it[0];
                int edge = it[1];
                
                if (distance[adjNode] > edge + dist)
                {
                    distance[adjNode] = dist + edge ; 
                    pq.push({distance[adjNode] , adjNode});
                }
            }
        }
        
        return distance ; 
    }