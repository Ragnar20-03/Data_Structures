// Date: 2024-06-17
// Day: Monday

#include<iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

// Brute force is double loop 
 
// Better 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       map < int , int > mp ; 
       for (int i = 0 ; i < nums.size() ; i++ )
       {
            if (mp.find ( target - nums[i]) != mp.end() )
            {
                return { i , mp[target-nums[i]]};
            }
            mp[nums[i]] = i ; 
       }
       return { 0 , 0 };
    }
};

// Optimal