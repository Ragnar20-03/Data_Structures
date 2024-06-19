// Date: 2024-06-19
// Day: Wednesday

#include<iostream>
#include <vector>
#include <set>
#include <map>
#include<unordered_map>
using namespace std;

//  Brute Force

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(int n, int arr[]) {
        // Code here
         
        vector<int >ans ; 
        for (int i= 0 ; i < n ; i++ )
        {
            bool bFlag = true ;
            for (int j = i + 1 ; j < n ; j++ )
            {
                if (arr[i] < arr[j])
                {
                    bFlag = false ; 
                    break ; 
                }
            }
            if (bFlag)
            {
                ans.push_back(arr[i]);
            }
        }
        return ans  ; 
    }
};


// Optimal only o(N) time complexity and o ( N ) Space complexity at worst


class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(int n, int arr[]) {
        // Code here
        vector<int >ans ; 
        int max = -1 ; 
        for (int i = n -1 ; i >= 0 ; i-- )
        {
            if (max < arr[i])
            {
                max = arr[i];
            }
            if (arr[i] >= max)
            {
                ans.push_back(arr[i]);
            }
        }
        reverse ( ans.begin() , ans.end());
        return ans  ; 
    }
};

int main () 
{


  return 0;
}
