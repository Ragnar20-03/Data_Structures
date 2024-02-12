class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size() ; 
        int m = grid[0].size() ; 

        int visited[10][10] = { 0 };
        //  {{int , int } , time}
        queue < pair < pair < int , int  >  , int >> q ; 
        int rotten = 0 ; 
        for (int i = 0 ; i< n ; i++ )
        {
            for (int j = 0 ; j< m ; j++ )
            {
                if (grid[i][j] == 2 ) 
                {
                    visited[i][j] = 2 ; 
                    q.push({{i , j } , 0});
                    
                }
                else if (grid[i][j] == 1 )
                {
                    rotten ++ ; 
                }
            }
        }
        int time = 0 ; 
        int noRotten = 0 ; 
        while (q.empty() == false)
        {
            int row = q.front().first.first ; 
            int col = q.front().first.second ; 
            int tm = q.front().second ; 
            q.pop() ; 
            time = max(time , tm);
            int delRow[] = { -1 , 0 , 1 , 0 };
            int delCol [] = {0 , 1 , 0 , -1 };
            for (int i = 0 ; i< 4 ; i++)
            {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];
                if (newCol < m && newRow < n && newCol >= 0 && newRow >= 0 && 
                    grid[newRow][newCol] == 1 && visited[newRow][newCol] != 2 )
                {
                    noRotten ++ ; 
                    visited[newRow][newCol] = 2 ; 
                    q.push({{newRow , newCol} , tm + 1 });
                }
            }
        }
        if (noRotten == rotten)
        {
            return time ; 
        }
        return -1 ; 
    }
};