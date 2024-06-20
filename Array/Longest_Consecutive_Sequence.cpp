// Date: 2024-06-20
// Day: Thursday

#include<iostream>
#include <vector>
#include <set>
#include <map>
#include<unordered_map>
#include <unordered_set>
using namespace std;


// Better

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    sort (arr.begin() , arr.end()); 
    int lastSmaller = INT_MIN ; 
    int cnt = 0 ; 
    int longest = 1 ; 
    for (int i = 0 ; i < n ; i++ )
    {
        if ( arr[i] -1 == lastSmaller)
        {
            cnt ++ ; 
            lastSmaller = arr[i];
        }
        else if ( lastSmaller != arr[i])
        {
            cnt = 1 ; 
            lastSmaller = arr[i];
        }
        longest = max ( longest , cnt  );
    }
    return longest ; 
}

//  OPTIMAL 
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    unordered_set < int > st ; 
    int longest = 1 ; 
    int cnt = 1 ; 
    for (int i = 0 ; i < n ; i++ )
    {
        st.insert( arr[i]);
    }

    for (auto it : st )
    {
        int x = it ; 
        cnt = 1 ; 

        while  ( st.find ( x + 1 ) != st.end())
        {
            cnt ++ ; 
            x = x + 1;
        }
        longest = max ( longest , cnt);
    }
    return longest ; 
}

int main () 
{


  return 0;
}
