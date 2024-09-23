// Date: 2024-09-23
// Day: Monday

#include<iostream>
#include <vector>
#include <set>
#include <map>
#include<unordered_map>
using namespace std;

class Solution {
public:
    void transform ( string  & s )
    {
        string res ="";
        for (int i = 0 ; i < s.size() ; i++ )
        {
            if ((s[i] <= 'z' && s[i] >='a') || (s[i] >='A' && s[i] <='Z') || 
                s[i] >= '0' && s[i] <='9' )
            {
                res += tolower(s[i]);
            }
        }
        s = res ; 
    }
    bool isPalindrome(string s) {
        transform(s);
        cout<<"String is : "<< s << endl;
        int l = 0 ; 
        int r = s.size() -1 ; 

        while ( l <= r )
        {
            if (s[l] != s[r])
            {
            cout<<"Compairing "<< s[l] <<" : "<< l  << " with "<<s[r]<< " : " << r<<endl;
                break ; 
            }
            l++ ; r--;
        }   
        if ( l <= r )
        {

            return false ; 
        }
        return true ; 
    }
};

int main () 
{


  return 0;
}
