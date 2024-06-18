// Date: 2024-06-17
// Day: Monday

#include<iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;


/*
75. Sort Colors
Solved
Medium
Topics
Companies
Hint
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function
*/


//  DUTCH_NATIONAL_FLAG_ALGORITHM

// 1st ( ~mine ) O ( 2n )
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0 , white = 0 , blue = 0 ; 

        for ( int i = 0 ;  i < nums.size() ; i++ )
        {
            if (nums[i] == 0 )red ++ ; 
            else if (nums[i] == 1 )white ++ ; 
            else blue ++ ; 
        }
        int i = 0 ; 
        while ( red -- )
        {
            nums[i] = 0 ; 
            i++ ; 
        }
        while ( white -- )
        {
            nums[i] = 1 ;
            i++ ; 
        }
        while ( blue -- )
        {
            nums [ i ] = 2 ; 
            i++ ;
        }
    }
    
};


// Dutch National Flag Algotithm 

//Optimal
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int mid = 0 ; 
        int low = 0 ; 
        int high = nums.size() - 1 ; 

        while ( mid <= high)
        {
            if ( nums [ mid] == 0  )
            {
                swap ( nums[low] , nums[mid]);
                low ++ ; 
                mid ++ ; 
            }
            else if ( nums[mid] == 2 )
            {
                swap (nums[mid] , nums[high]);
                high -- ; 
            }
            else 
            {
                mid ++ ; 
            }
        }
    }
};