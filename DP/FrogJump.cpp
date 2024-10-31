#include<iostream>
#include<vector>
using namespace std ; 

// 1 ; Recurrsion :

// frog can jump either 1 or 2 steps 
//  return the minimum energy consume to react nth step ;

// shortcut : 
// 1  express in terms on indexes ; 
// 2 Do all the stuff on that index ;
// 3   According to the problem :
//      1) count / sum  all steps / solutions 
//      2) Take min / maximum  from above step

int helper ( int i , vector<int > & height )
  {
      if ( i == 0 )
      {
          return 0 ; 
      }
      
      int left = helper ( i - 1 , height) + abs(height[i] - height [ i -1]);
      if (i > 1)
      {
        int right = helper ( i - 2 , height) + abs ( height [ i]- height[i-2]);
        return min ( left , right);
      }
      return left ; 
      
  }
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        return helper ( n-1 , height);
    }

// 2 : Memoization
// Add the dp array to memoize the previous computation to solve the extra stack space and time complexity.
int helper ( int i , vector<int > & height , vector<int > & dp )
  {
      if ( i == 0 )
      {
          return 0 ; 
      }
      if (dp [ i ] != -1 )
      {
          return dp [ i ];
      }
      int left = helper ( i - 1 , height , dp ) + abs(height[i] - height [ i -1]);
      if (i > 1)
      {
        int right = helper ( i - 2 , height , dp) + abs ( height [ i]- height[i-2]);
        return dp [i ] = min ( left , right);
      }
      return  dp[i] = left ; 
      
  }
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int> dp ( n , -1 );
        return helper ( n-1 , height , dp);
    }

// 3  Tabulation : convert it into the Tabulation .