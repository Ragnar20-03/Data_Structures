#include<iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

// 1st Approach 
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n  = nums.size() ; 
        int i = 0 ; 
        for (int j = 0  ; j < n ; j++ )
        {
            if ( nums[j] != 0 )
            {
                nums[i] = nums[j];
                i++ ; 
            }
        }
        while ( i< n )
        {
            nums[i] = 0 ; 
            i++;
        }

    }
};

// 2nd Approach 
// Instead of another while loop swap it bith are same ; 
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n  = nums.size() ; 
        int j = -1 ; 
        for (int i = 0 ; i < n ; i++ )
        {
            if (nums [ i ] == 0 )
            {
                    j = i ; 
                    break;
            }   
        }
        if (j == -1 )return ; 
        for (int i = j + 1 ; i < n ; i++ )
        {
            if (nums[i] != 0 )
            {
                nums[j] = nums[i];
                nums[i] = 0 ; 
                j++ ; 
            }
        }
    }
};