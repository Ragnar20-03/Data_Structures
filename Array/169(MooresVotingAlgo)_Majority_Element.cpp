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

// Brute Force : use 2 loops O ( n2 );

// Better -> 
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

// Optimal 


//MOORES VOTING ALGORITHM 

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele = 0 ; 
        int cnt = 0 ; 
        for (int i = 0 ; i < nums.size() ; i++ )
        {
            if (cnt == 0 )
            {
                ele = nums[i];
                cnt =1 ;
            }
            else if (nums[i] == ele)
            {
                cnt ++ ; 
            }
            else 
            {
                cnt -- ; 
            }
        }
        return ele ; 
    }

    //can also verify is it so or not ; 
};