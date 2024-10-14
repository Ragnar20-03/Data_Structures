#include<iostream>
#include<vector>
using namespace std ; 

class Solution {
public:
    bool isSafe (int row , int col , vector<string > & board , int n ) 
    {
        // preserving before values as it changes 
        int prevRow = row ; 
        int prevCol = col ; 

        // checking left Upper Diagonal 
        while ( row >= 0 && col >=0 )
        {
            if ( board [ row ] [ col ] == 'Q')
            {
                return false ; 
            }
            // else check upper left diagonal cell 
            col -- ; 
            row -- ; 
        }

        // Checkinh left side 
        col = prevCol ; // Preserved Values are used here
        row = prevRow ; // Preserved Values are used here

        while ( col >=0 )
        {
            if (board[row][col] == 'Q')
            {
                return false ; 
            }
            col -- ; // else check next left cell  ; 
        }

        // checking lower left diagonal 
        col = prevCol ; // Preserved Values are used here
        row = prevRow ; // Preserved Values are used here

        while ( row < n && col >=0 )
        {
            if (board [ row ] [ col ]== 'Q')
            {
                return false ; 
            }
            // else check nect left lower diaginal cell 
            row ++ ; 
            col -- ; 
        }

        // and if not present any Then it is safe 
        return true ; 
    }
    void solve (  int col , int n , vector<string> & board , vector<vector<string>>&ans  )
    {
        if (col >= n )
        {
            ans.push_back(board) ; 
            return ; 
        }

        for (int row = 0 ; row < n ; row ++ )
        {
            if (isSafe ( row , col , board , n ))
            {
                board[row][col] = 'Q';
                solve(col + 1 , n , board , ans);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string > > ans ; 
        vector< string > board ( n) ;
        string s ( n ,'.') ; 

        for (int i = 0 ; i < n ; i++ )
        {
            board [ i ] = s ; 
        }
        solve (0 , n , board , ans);
        return ans ; 
    }
};