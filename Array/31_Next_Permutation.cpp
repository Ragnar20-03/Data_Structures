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
    first find the break point : (initiallize it to -1 )
      eg = from last of array find first index i.e ( arr[i] < arr[i+1]) 
      this is the index from which we have to make changes in order to find next permutation 
    
    find next smallest  greater element to breakpoint from  that breakpoint index to last of array and swap them in order to find next permutation 

    reverse the array form breakpoint index + 1 to n-1 ;

    this will give us the next minium permutation 
*/

vector<int> nextGreaterPermutation(vector<int> &a) {
    // Write your code here.
    int n = a.size() ; 
    int breakPointIndex = -1 ; 

// Find Break Point ; 
    for (int i = n -2 ; i >= 0 ; i-- ) 
    {
        if (a[i] < a[i+1])
        {
            breakPointIndex = i ; 
            break ; 
        }
    }
    // if index == -1 then no breakpoint the next permutation is smallest number hence reverse array 
    if ( breakPointIndex == -1 )
    {
        reverse( a.begin () , a.end() );
        return a ; 
    }

//ELSE find the smallest greater element from breakpoint index + 1 to n-1 ; 

    for (int i = n-1 ; i > breakPointIndex ; i--)
    {
        if ( a[i] > a[breakPointIndex])
        {
            swap ( a[i] , a[breakPointIndex]);
            break;
        }
    }

// reverse the array from breakPointIndex + 1 to n-1 
    reverse(a.begin() + breakPointIndex + 1 , a.end() );
    return a ; 

}