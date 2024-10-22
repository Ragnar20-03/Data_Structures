#include<iostream>
#include<vector>

using namespace  std ;

//{ Driver Code Starts
//Initial Template for C++
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool checkConsecutive (string &temp  )
    {
        int i = 1 ;
        int j = i -1 ; 
        for (i = 1 ; i < temp.size() ; i++ )
        {
            if ( temp[i] == temp[j]  && (temp[i] == '1' || temp[j] == '1' ))
            {
                return true;
            }
            j++;
        }
        return false ; 
    }
    void generateSubString ( int i , int n , vector<string > & ans , 
    string temp )
    {
        if (i >= n )
        {
        // cout<< " I is : "<<i<<endl;
            if (!checkConsecutive(temp))
            {
                ans.push_back(temp);
            }
            return ; 
        }
        
        temp.push_back('0');
        // cout<<"Left substring is : "<<temp<<endl;
        generateSubString(i+1 , n , ans , temp);
        
        temp.pop_back();
        temp.push_back('1');
        // cout<<"Right substring is : "<<temp<<endl;
        generateSubString(i +1  , n , ans , temp );
    }
    vector<string> generateBinaryStrings(int num){
        //Write your code
        vector < string > ans ; 
        string temp ="" ;
        generateSubString( 0 , num , ans , temp);
        return ans ; 
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        
        vector<string> v = obj.generateBinaryStrings(n);
        for(auto it:v) cout<<it<<" ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends


// 2nd Approach " 
//  by just applying single logic that no consecutive one must have same 1 
// we can remove the checkConsecutive function and reduce timecomplexxity also 