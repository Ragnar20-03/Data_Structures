#include <vector>
#include<iostream>
#include <queue>
using namespace std ;
int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        if (source == destination) return 0 ; 
        int delRow [] = { -1 , 0 , 1 , 0 } ; 
        int delCol [] = { 0 , 1 , 0 , -1 } ; 
        int n = grid.size() ; 
        int m = grid[0].size() ; 
        queue< pair < int , pair < int , int > > > q; 
        q.push({0 , source});
        vector<vector<int > > distance ( n , vector<int > ( m , INT_MAX));
        
        distance[source.first][source.second] = 0 ; 
        
        while (q.empty() == false )
        {
            int dist = q.front().first ; 
            int r = q.front().second.first ; 
            int c = q.front().second.second ; 
            q.pop() ; 
            
            for (int i = 0 ; i < 4 ; i++ )
            {
                int newRow = delRow [ i ] + r ; 
                int newCol = delCol [ i ] + c ; 
                
                if (newRow < n && newCol < m && newRow >= 0 && newCol >=0 
                    && grid[newRow][newCol] ==1 && 
                    distance[newRow][newCol] > dist + 1  )
                {
                    distance[newRow][newCol] = dist + 1 ; 
                    if (newRow == destination.first && newCol == destination.second)
                    {
                        return dist + 1 ;
                    }
                    q.push({dist + 1 , {newRow , newCol}});
                    
                }
            }
    
        }
        return -1 ; 
    }