// Date: 2024-06-20
// Day: Thursday

#include<iostream>
#include <vector>
#include <set>
#include <map>
#include<unordered_map>
using namespace std;


// Brute Force

//  Algorithm 
  /* 
    first find zero and take visited array initiallize to false
    mark the whole row and coloum as true  

    loop again to find which index is true mark it as 0 
  */
class Solution {
public:
    void markRowZero ( int i , int m , vector<vector<bool > > & vis ,
    vector<vector<int  > > & mat )
    {
        for (int j = 0 ; j < m ; j ++ )
        {
            if (mat[i][j] != 0 )
            {
                vis[i][j] = true ; 
            }
        }
    }
    void markColZero ( int j , int n  , vector<vector<bool > > & vis ,
    vector<vector<int  > > & mat )
    {
        for (int i = 0 ; i < n ; i++ )
        {
            if (mat[i][j] != 0 )
            {
                vis [ i ] [ j ] = true ; 
            }
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size() ; 
        int m = matrix[0].size() ; 
        vector<vector<bool > > visited ( n , vector<bool > ( m , false));

        for (int i = 0 ; i < n ; i++ )
        {
            for (int j = 0 ; j < m ; j++ )
            if (matrix[i][j] == 0 )
            {
                markRowZero ( i , m , visited ,matrix);
                markColZero ( j , n , visited , matrix);
            }
        }

        for (int i = 0 ; i < n ; i++ )
        {
            for (int j = 0 ; j < m ; j++ )
            if (visited[i][j] == true )
            {
                matrix[i][j] = 0 ; 
            }
        }

    }
};

int main () 
{


  return 0;
}
