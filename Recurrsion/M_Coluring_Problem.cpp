//{ Driver Code Starts
#include <iostream>
#include<vector>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isSafe ( int node , vector<int > adj []  , int currColor , 
    int n , int m  , vector<int > &color)
    {
        for (auto it : adj [ node ])
        {
            if (color[it] == currColor )
            {
                return false ; 
            }
        }
        return true ; 
    }
    bool solve ( int node , vector<int > adj  [] , int n  , int m , 
        vector<int>&color  )
    {
        if (node == n )
        {
            return true ; 
        }
        for (int i = 1 ; i <= m ; i++ )
        {
            if (isSafe ( node , adj , i , n , m , color ))
            {
                color[node ] = i ; 
                if (solve(node + 1 , adj , n , m , color) == true)
                {
                    return true ; 
                }
                color [ node ] = 0 ; 
            }
        }
        return false ; 
    }
    bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
        // code here
        vector<int > adj [ v ]  ; 
        vector<int > color ( v , 0 ) ; 
        for (auto it : edges )
        {
            adj[it.first].push_back(it.second);
            adj[it.second].push_back(it.first);
        }
        
            
        return solve (0 , adj , v  , m , color);
    }
};

//{ Driver Code Starts.

// int main() {
//     int t;
//     cin >> t;
//     cin.ignore();
//     while (t--) {
//         int n, m;
//         cin >> n;
//         cin.ignore(); // Ignore newline after reading n
//         vector<int> arr;
//         string input;
//         getline(cin, input); // Read the entire line for the array elements

//         stringstream ss(input);
//         int number;
//         while (ss >> number) {
//             arr.push_back(number); // Populate the array with edge values
//         }
//         cin >> m;
//         cin.ignore(); // Ignore newline after reading m

//         int edges_count = arr.size();
//         vector<pair<int, int>> edges(edges_count /
//                                      2); // Correct size of the edges vector

//         for (int i = 0; i < edges_count; i += 2) {
//             int l1 = arr[i];
//             int l2 = arr[i + 1];
//             edges[i / 2] = {l1, l2}; // Properly assign the pair
//         }

//         Solution ob;
//         cout << (ob.graphColoring(n, edges, m) ? "true" : "false")
//              << endl; // Call the graph coloring function
//     }
//     return 0;
// }

// } Driver Code Ends