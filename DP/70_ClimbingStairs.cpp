// Step 1 : Simple recurrsion
#include<vector>
using namespace std ;

class Solution {
public:
int helper ( int i )
{
    if (i == 1 || i == 0 )
    {
        return 1 ; 
    }

    return helper ( i -1 ) + helper ( i -2 );
}
    int climbStairs(int n) {
        return helper ( n );
    }
};

// Step 2 : Memoiziation

class Solution {
public:
    int helper ( int i  , vector<int > & dp)
    {
        if (i == 1 || i == 0 )
        {
            return 1 ; 
        }
        if (dp [ i ] != -1 )
        {
            return dp[i];
        }

        return dp[i] =  helper ( i -1 , dp ) + helper ( i -2  ,dp);
    }
    int climbStairs(int n) {
        vector<int >dp ( n + 1 , -1 );
        return helper ( n  , dp);
    }
};

//STEP 3 : TABULATION : REMOVING EXTRA SPACe complexity of recurrsion stack space 

    int climbStairs(int n) {
        vector<int >dp ( n + 1 , -1 );
        dp[0] = 1 ; 
        dp[1] = 1 ;
        for (int i = 2 ; i<=n ; i++ )
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }