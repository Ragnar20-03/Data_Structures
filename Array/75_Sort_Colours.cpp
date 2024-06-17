// Date: 2024-06-17
// Day: Monday

#include<iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;



// Brute Force 
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