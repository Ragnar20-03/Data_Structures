// Date: 2024-06-18
// Day: Tuesday

#include<iostream>
#include <vector>
#include <set>
#include <map>
#include<unordered_map>
using namespace std;

// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

// Brute Force
// algorithm  : 
    /*
        use hashmap to store the no of occurences of numbers ;
    */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map < int , int > mp  ; 
        for (int i = 0 ; i < nums.size() ; i++ )
        {
            mp[nums[i]] ++ ; 
            if (mp[nums[i]] > nums.size() / 2 )
            {
                return nums[i];
            }
        }
        return -1  ; 
    }
};