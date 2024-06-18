// Date: 2024-06-18
// Day: Tuesday

#include<iostream>
#include <vector>
#include <set>
#include <map>
#include<unordered_map>
using namespace std;

// OPTIMAL 
//  KADENS ALGORITHM used for maximum sub array sum in linear time complexity o ( n ) and TC =  o (1 );

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN ; 
        int sum = 0 ; 
        for (int i = 0 ; i < nums.size() ; i++ )
        {
            sum = sum + nums[i];
            ans = max ( ans , sum);
            if (sum < 0 )
            {
                sum = 0 ; 
            }
        }
        return ans ; 
    }
};

// brute  Not Working 

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int ans = INT_MIN ;
        for (int i = 0 ; i < nums.size() ; i++ )
        {
            for (int j = i ; j < nums.size() ; j++ )
            {
                int sum = 0 ; 
                for (int k = i ; k <= j ; j++ )
                {
                    sum = sum + nums[k] ;
                }
                ans = max ( sum , ans);
            }
        }
        return ans ; 
    }
};