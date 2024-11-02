#include<iostream>
#include<vector>
using namespace std ; 

// MY SOlution
class Solution {
public:
    int helper ( int i , vector<int > & nums , int &sum , int ans  )
    {
        if (i >= nums.size())
        {
            ans = max ( sum , ans);
            cout<<"ans is : "<<ans<<endl;
            return ans  ;
        }
        sum += nums[i];
        cout<<"FOR NUMS{i} : "<<nums[i]<<" : Sum is : "<<sum<<endl;
        int ca = 0 ; 
        for (int j = i+2 ; j <= nums.size() ; j++ )
        {

            ca = helper (j , nums , sum  , ans  );
            if (j == nums.size() )continue ; 
            sum -= nums[ j ];
        }
        return ca ; 
    }
    int rob(vector<int>& nums) {
        int ans = 0 ; 
        int fs = 0 ; 
        int ss = 0 ; 
        cout<<helper ( 0 , nums , fs , ans);
        cout<<"---------------------\n";
        cout<<helper ( 1 , nums , ss , ans );
        return ans ; 
    }
};


// 1  Recurrsion pick and not pick only differnce is to not pick adjecent values ; 
    int helper ( int i  , vector<int > & nums )
    {
        if (i == nums.size() - 1)
        {
            return nums [ i ] ; 
        }
        if ( i >= nums.size() )return 0 ; 

        int pick = nums[i] + helper ( i + 2 , nums ) ; 
        int notPick = helper ( i + 1 , nums);
        return max ( pick , notPick);

    }
    int rob(vector<int>& nums) {
            return helper ( 0 , nums );
    }

    // or 

    int helper ( int i  , vector<int > & nums )
    {
        if (i == 0 )
        {
            return nums [ i ] ; 
        }
        if ( i < 0  )return 0 ; 

        int pick = nums[i] + helper ( i - 2 , nums ) ; 
        int notPick = helper ( i - 1 , nums);
        return max ( pick , notPick);

    }
    int rob(vector<int>& nums) {
            return helper ( nums.size() - 1  , nums );
    }   


    // MEMOIZATION  TC = O(n) SC = o(n) + O (n);
    int helper ( int i  , vector<int > & nums , vector<int> &dp )
    {
        if (i == 0 )
        {
            return nums [ i ] ; 
        }
        if ( i < 0  )return 0 ; 
        if (dp[i] != -1 )
        {
            return dp[i];
        }

        int pick = nums[i] + helper ( i - 2 , nums  , dp ) ; 
        int notPick = helper ( i - 1 , nums , dp );
        return dp[i] =  max ( pick , notPick);

    }
    int rob(vector<int>& nums) {
            vector<int > dp ( nums.size(), -1 ) ; 
            return helper ( nums.size() - 1  , nums , dp );
    }

    // Tabulation TC = o(n) SC = o(n);
    int maximumNonAdjacentSum(vector<int> &nums){
    vector<int> dp ( nums.size() , 0  );
    dp [ 0 ] = nums [ 0 ];
    for (int i = 1 ; i < nums.size() ; i++ ) 
    {
        int take = nums [ i ]; // if i - 2 is negative then only take that current element .  
        if (i - 2 >= 0 ) {
            take += dp [ i - 2 ]; // else take that prev element 
        }
        int notTake = 0 + dp [ i - 1 ];
        dp[i] = max ( take , notTake);
    }
    return dp [ nums.size() - 1 ];
}

    // Space Optimization TC = o(n) SC = none ;

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int prev2 = 0 ; 
    int prev = nums[0] ; 
    for (int i = 1 ; i < nums.size() ; i++ ) 
    {
        int take = nums[i] ;
        if ( i > 1 )
        {
            take += prev2 ; 
        }
        int notTake = prev ; 

        int curri = max ( take  , notTake);

        prev2 = prev ; 
        prev = curri;
    }
    return prev;
}