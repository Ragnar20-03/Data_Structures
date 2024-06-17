// Date: 2024-06-17
// Day: Monday

#include<iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;


// this has differnt better and brute force approach 

// OPTIMAL is : 

// Algorithm  : 
/*              
                the xor 2 any number is that umber is it self
                eg = 2 ^ 2 =  0 ;
                2 ^ 2 ^ 2 ^ 2 = 0 ^ 0 = 0 ;        
                2 ^ 2 ^ 3 = 0 ^ 3 = 3 
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xor1 = 0 ; 
        for (int i = 0 ; i < nums.size() ; i++ )
        {
            xor1 = xor1 ^ nums [ i ] ; 
        }
        return xor1 ; 
    }
};
