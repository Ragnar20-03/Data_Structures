     #include<iostream>
        using namespace  std ; 
        
     #include<vector>
     #include<set>


     // Using SET Data Structures !
     vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        set < pair <int , int > > st ; 
        vector<int > distance ( V , 1e9);
        distance[S] = 0 ; 
        
        st.insert({0 , S});
        
        while (st.empty() == false )
        {
            auto it = *(st.begin());
            int node = it.second ; 
            int dist = it.first ; 
            st.erase(it);
            
            for (auto it : adj [ node])
            {
                int adjNode = it[0];
                int weight = it[1];
                
                if (dist + weight < distance[adjNode])
                {
                    if (distance[adjNode] != 1e9)
                    {
                        st.erase({distance[adjNode] , adjNode});
                    }
                    
                    distance[adjNode] = dist + weight ; 
                    st.insert({distance[adjNode] , adjNode});
                }
            }
        }
        return distance ; 
    }