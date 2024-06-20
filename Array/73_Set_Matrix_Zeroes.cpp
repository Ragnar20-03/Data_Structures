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

////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////

// BETTER Approach
 /*
    ALGORITHM  : 
      1st : initialize the rowTrack and ColTrack array of size n and m respectively and set both to zero ; 

      2 :  iterate for whole matrix and if matrix[i][j]== 0 then mark that row and coloum 1 in the row Track and colTrack array ; 

      3 : 
        Re Iterate the array , and check if that corrosponding row ( i ) or coloumn ( j )is marked as one ( ~ means on that row or coloumn zero is found) ; and marked them as 0 ; 
 */

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size() ; 
        int m = matrix[0].size() ; 

        vector<int > rowTrack ( n , 0 );
        vector<int > colTrack ( m , 0 );

        for (int i = 0 ; i < n ; i++ )
        {
            for (int j = 0 ; j < m ; j++ )
            {
                if (matrix[i][j] == 0 )
                {
                    rowTrack[i] = 1 ; 
                    colTrack[j] = 1 ; 
                }
            }
        }

        for (int i = 0 ; i < n ; i++)
        {
            for (int j = 0 ; j < m ; j++ )
            {
                if (rowTrack[i] == 1 || colTrack[j] == 1) 
                {
                    matrix[i][j] = 0 ; 
                }
            }
        }
    }
};

////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////

int main () 
{


  return 0;
}
