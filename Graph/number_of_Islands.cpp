//{ Driver Code Starts
using namespace std;

// } Driver Code Ends
class Solution {
    private : 
    void bfs(int row , int col , vector< vector<int> > &visited , vector<vector<char> > grid)
    {
        queue<pair<int , int > >  q;
        q.push({row , col});
        int n = grid.size() ; 
        int m = grid[0].size() ; 
        
        while (q.empty() == false)
        {
            int row = q.front().first ; 
            int col = q.front().second;
            
            q.pop() ; 
            
            for (int delRow = -1 ; delRow <=1 ; delRow ++)
            {
                for (int delCol = -1 ; delCol <= 1 ; delCol ++)
                {
                    int nRow = row + delRow ; 
                    int nCol = col + delCol; 
                    
                    if (nRow < n && nRow >= 0 && nCol < m  && nCol >= 0 && visited[nRow][nCol] != 1 && grid[nRow][nCol] == '1')
                    {
                        visited[nRow][nCol] = 1 ; 
                        q.push({nRow , nCol});
                    }
                }
            }
        }
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size() ; 
        int m  = grid[0].size() ; 
        vector <vector <int > >  visited (n , vector<int>(m , 0 ));
        int iCnt = 0; 
        for (int i = 0 ; i < n ; i++ )
        {
            for (int j = 0 ; j< m ; j ++)
            {
                if (grid [i][j] == '1' && visited[i][j] != 1)
                {
                    iCnt++;
                    bfs(i , j  , visited , grid);
                }
            }
        }
        return iCnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends