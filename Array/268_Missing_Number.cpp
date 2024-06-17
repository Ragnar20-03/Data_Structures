// Date: 2024-06-17
// Day: Monday

#include<iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

 /////
/*
    Follow up: Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?

*/
 //

// 1st 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size () ; 
        sort ( nums.begin () , nums.end() ) ;
        for (int i = 0 ; i < n ; i++ )
        {
            if ( i != nums[i])
            {
                return i;
            }
        }
        return n ; 
    }
};

// 2nd Better Approach TC = O ( n ) + O ( n )  
                    //  SC = O (n) + extra O ( n )


int missingNumber(vector<int>& nums) {
        int n = nums.size () ; 
        vector<int >  visited (n + 1 , 0);
        for (int i = 0 ; i < n ; i++ )
        {
            visited[nums[i]] = 1 ; 
        }
        for (int i = 0 ; i <= n  ; i ++ )
        {
            if (visited[i ] != 1 )
            {
                return i ; 
            }
        }
        return n ; 
    }
// Optimal
//   Optimize Time Complexity and space complexity  
/*
        Approach :  find sum of all elements that are present ; 
                    calculate sum of all numbers from 1 to n ; 
                    ( N * (N + 1 ) ) / 2 is the sum of natural number from 0 to n or 1 to n ;
                    subtract both to get final answer
*/

    int missingNumber(vector<int>& nums) {
        int n = nums.size () ; 
        
        int sum = (n * (n + 1 )) / 2 ; 
        int sum2 = 0 ; 
        for (int i = 0 ; i < n ; i++ )
        {
            sum2 += nums[i];
        }
        return sum - sum2  ; 
    }