// Date: 2024-06-18
// Day: Tuesday

#include<iostream>
#include <vector>
#include <set>
#include <map>
#include<unordered_map>
using namespace std;

// Alternate the array elements in positive and negative elements in alternative manner , first comes positive ;
// Brute Force 
vector<int> alternateNumbers(vector<int>&a) {
    // Write your code here.
    vector<int > pos ; 
    vector<int > neg ; 
    vector<int > ans;

    for (int i = 0 ; i < a.size() ; i++ )
    {
        if (a[i] >= 0 )
        {
            pos.push_back(a[i]);
        }
        else {
            neg.push_back(a[i]);
        }
    }
    for (int i = 0 ; i < a.size() / 2 ; i++ )
    {
        ans.push_back(pos[i]);
        ans.push_back(neg[i]);
    }
    return ans ; 
}

// Without using extra array of ans 
vector<int> alternateNumbers(vector<int>&a) {
    // Write your code here.
    vector<int > pos ; 
    vector<int > neg ; 


    for (int i = 0 ; i < a.size() ; i++ )
    {
        if (a[i] >= 0 )
        {
            pos.push_back(a[i]);
        }
        else {
            neg.push_back(a[i]);
        }
    }
    for (int i = 0 ; i < a.size() / 2 ; i++ )
    {
        a[2 * i] = pos[i]; // even index ; 
        a[2 * i + 1 ]= neg[i]; // odd index ; 
    }
    return a ; 
}

// Optimal Approach 
    // Algo : 
    /*
        store the current positive and negative indices 
        and store the numbers accordingly
    */
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int posIndex = 0 ; 
        int negIndex = 1; 
        vector<int > ans = nums ; 
        for (int i = 0 ; i < nums.size() ; i++ )
        {
            if ( nums[i] >= 0 )
            {
               ans[posIndex] = nums[i];
                posIndex += 2 ; 
            }
            else 
            {
                ans[negIndex] = nums[i];
                negIndex += 2 ; 
            }
        }
        return ans ; 
    }
};