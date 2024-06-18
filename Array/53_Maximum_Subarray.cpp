// Date: 2024-06-18
// Day: Tuesday

#include<iostream>
#include <vector>
#include <set>
#include <map>
#include<unordered_map>
using namespace std;


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