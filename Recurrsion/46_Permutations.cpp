#include<iostream>
#include<vector>
using namespace std ; 

class Solution {
public:

    void findPermutations( int n , vector<int> & nums , vector<int > & temp , 
    vector<vector<int > > & ans , vector<bool> &taken)
    {
        if (temp.size() == n )
        {
            ans.push_back(temp) ; 
            return ; 
        }

        for (int i = 0 ; i < n  ; i++ )
        {
            if (taken[i] == false )
            {
                taken[i] = true ; 
                temp.push_back(nums[i]);
                findPermutations( n , nums , temp , ans , taken );
                taken[i] = false ; 
                temp.pop_back() ; 

            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int > > ans ; 
        int n = nums.size() ; 
        vector<int> temp ; 
        vector<bool > taken ( n , false ); 

        findPermutations( n , nums , temp , ans , taken) ; 
        return ans ; 
    }
};

// 2nd Approach - Not using extra Space 

class Solution {
public:
    void findPermutations ( int index , int  n , vector<int > & nums , 
    vector<vector<int > > & ans )
    {
        if (index >= n )
        {
            ans.push_back(nums) ; 
            return ; 
        }

        for (int i = index ; i < n ; i++ )
        {
            swap(nums[i] , nums[index]) ; 
            findPermutations(index + 1 , n , nums  , ans)  ; 
            swap(nums[i] , nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int > > ans ; 

        int n = nums.size() ; 
        findPermutations ( 0 , n , nums , ans);

        return ans ; 
    }
};