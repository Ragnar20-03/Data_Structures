class Solution {
    private : 
    void dfs(int row , int col , vector<vector<int > > &visited , vector<vector<char > > board , vector<vector<char > > &ans , int n , int m , int delRow[] , int delCol[])
    {
        visited[row][col] = 1 ; 
        ans[row][col] = 'O';
        for (int i  = 0 ; i < 4 ; i++ )
        {
            int newRow = row + delRow[i];
            int newCol = col + delCol[i]; 
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && board[newRow][newCol] == 'O' && visited[newRow][newCol] != 1  )
            {
                dfs(newRow , newCol , visited , board , ans  , n , m , delRow , delCol);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size() ; 
        int m  = board[0].size() ; 
        int delRow [] = { -1 , 0 , 1 , 0 };
        int delCol [] = { 0 , 1 , 0 , -1 };
        vector<vector<int > > visited ( n , vector<int > ( m  , 0 ));
        vector<vector<char > > ans ( n , vector<char > ( m  , 'X , ans ' ));
        for (int i = 0 ; i < m ; i++ )
        {
            if (board[0][i] == 'O' && visited[0][i] != 1 )
            {
                dfs(0 , i , visited , board , ans  , n , m , delRow , delCol);
            }
            if (board[n-1][i] == 'O' && visited[n-1][i] != 1 )
            {
                cout<<n-1 << " , "<<i<<endl;
                dfs(n-1 , i , visited , board , ans  , n , m , delRow , delCol);
            }
        }
        for (int i = 0 ; i <  n ; i++ )
        {
            if (board[i][0] == 'O' && visited[i][0] != 1 )
            {
                dfs(i , 0 , visited , board , ans  , n , m , delRow , delCol);
            }
            if (board[i][m-1] == 'O' && visited[i][m-1] != 1 )
            {
                dfs(i , m-1 , visited , board , ans  , n , m , delRow , delCol);
            }
        }

        for (int i = 0 ; i < n ; i++)
        {
            for (int j = 0 ; j < m ; j ++ )
            {
                if (visited[i][j] != 1 && board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};