// Date: 2024-06-19
// Day: Wednesday

#include<iostream>
#include <vector>
#include <set>
#include <map>
#include<unordered_map>
using namespace std;

// Optimal 
// INbuilt function for next permutation : next_permutation(arr.begin() , arr.end());

/*
  Algorithm : 
    first find the break point : 
      eg = from last of array find first index i.e ( arr[i] < arr[i+1]) 
      this is the index from which we have to make changes in order to find next permutation 
    
    find next smallest element from that breakpoint index to last of array and swap them in order to find next permutation 

    reverse the array form breakpoint index + 1 to n-1 ;

    this will give us the next minium permutation 
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size() ; 
        int ind = -1 ; 
        for (int i = n-2 ; i>= 0 ; i-- )
        {
            if (nums[i] < nums[i+1])
            {
                ind = i ; 
                break ; 
            }
        }
        if (ind == -1 )
        {
            reverse ( nums.begin() , nums.end() ) ; 
            return ; 
        }

        for ( int i = n-1 ; i > ind ; i--)
        {
            if (nums[ind] < nums[i])
            {
                swap ( nums[i] , nums[ind]);
                break ; 
            }
        }
        reverse( nums.begin() + ind + 1 , nums.end());
    }
};

int main () 
{


  return 0;
}
