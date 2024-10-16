//{ Driver Code Starts
// Initial template for C++

#include <iostream> 
#include<map>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    
    void dfs ( int row , int col , vector<vector< int > > & mat ,
        vector<vector<int > > & visited, vector<string> &ans  ,
         int n , int m  ,  int delRow [] , int delCol [] , map < int , char > & mp , string &str )
     {  
         
         if (row == n- 1 && col == n-1 ) // or m-1 
         {
             ans.push_back(str);
             return ; 
         }
         
         //go with D L R U  so no need to lecicographically ->
         //logic afterwards as we traverse in its oder already
        for (int i = 0 ; i < 4 ; i++ )
        {
            int newRow = row + delRow [ i ];
            int newCol = col + delCol [ i ]; 
            
            if (newRow < n && newCol < n && newRow >=0 && newCol >= 0 
                && visited [newRow][newCol] != 1 && mat[newRow][newCol] == 1)
            {
                visited [ row ] [ col ] = 1; 
                str.push_back(mp[i]);

                dfs(newRow , newCol , mat , visited , ans , n , m , delRow , delCol , mp , str);
                visited [ newRow ] [ newCol ] = 0 ; 
                str.pop_back() ; 
            }
        }
    }  
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        int n = mat.size() ; 
        int m = mat[0].size() ; 
        int delRow [ ] = { 1 , 0 , 0 , -1 } ; 
        int delCol [] = { 0 , -1 , 1 , 0  } ; 
        map < int , char > mp ; 
        mp[0] = 'D';
        mp[1] = 'L';
        mp[2] = 'R';
        mp[3] = 'U';
        string str = "";
        vector<vector<int > > visited ( n , vector<int > ( m , 0 )) ;
        vector<string > ans ;  
        if (mat[0][0] == 0 )return ans ; // first cell is empty ; 
        dfs ( 0 , 0 , mat ,visited , ans , n , m , delRow , delCol , mp , str );

        return ans ; 
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends