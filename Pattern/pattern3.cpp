#include <iostream> 
using namespace std ; 

int main () 
{
    int n ; 
    cin >> n ; 

// Not Woriknig
    for (int i = n ; i >=0 ; i-- )
    {
        //Space 
        for (int j = 0 ; j < (n - i - 1) ; j ++  )
        {
            cout<<" \t";
        }
        // Star
        for (int j = 0 ; j < (2* i + 1 ); j++  )
        {
            cout<<"*\t";
        }
        // Space 

        for (int j = 0 ; j < n - i - 1  ; j ++ )
        {
            cout<<" \t";

        }
        cout<<'\n';
    }
    return 0 ; 
}