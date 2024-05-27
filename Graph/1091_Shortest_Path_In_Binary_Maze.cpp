#include <vector>
#include <queue>
using namespace std ; 
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1 )return -1 ;
        else if (grid.size() == 1 )return 1 ;  
        queue < pair < int  , pair < int , int > > > q ;
        int n   = grid.size() ; 
        vector<vector<int > > distance ( n , vector<int > ( n , INT_MAX));
        q.push({1 , { 0 , 0 }});
        distance [ 0 ] [ 0 ] = 0 ; 

        while (q.empty() == false )
        {
            int dist = q.front().first ; 
            int r = q.front().second.first ; 
            int c = q.front().second.second ; 
            q.pop() ;

            for (int delRow = -1 ; delRow <= 1 ; delRow ++ )
            {
                for (int delCol = -1 ; delCol <= 1 ; delCol ++ )
                {
                    int newRow = delRow + r ; 
                    int newCol = delCol + c ; 
                    if (newRow >=0 && newCol >=0 && newRow < n && newCol < n
                    &&  grid[newRow][newCol] == 0 && distance[newRow][newCol] > dist + 1 )
                    {
                        distance[newRow][newCol] = dist + 1 ; 
                        if (newRow == n-1 && newCol == n-1 )
                        {
                            return dist + 1 ; 
                        }
                        q.push({dist + 1  , {newRow  , newCol}});

                    }
                }
            }
        }
            return -1 ; 
    }
};