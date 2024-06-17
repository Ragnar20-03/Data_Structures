// Date: 2024-06-17
// Day: Monday

#include<iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max =-1  ; 
        int temp = 0 ; 
        for (int i = 0 ; i < nums.size() ; i++ )
        {
            if ( nums [ i ] == 0 )
            {
                temp = 0 ;
            }
            else 
            {
                temp ++ ; 
                if (max <= temp )
                {
                    max = temp ; 
                }
            }
        }
        return temp > max ? temp : max ; 
    }
};