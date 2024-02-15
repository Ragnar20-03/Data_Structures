class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    visited[i][j] = 1;
                    q.push({{i, j}, 0});
                }
            }
        }

        while (q.empty() == false) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int step = q.front().second;
            ans[row][col] = step;
            q.pop();

            int delRow[] = {-1, 0, 1, 0};
            int delCol[] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++) {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];
                if (newRow < n && newCol < m && newRow >= 0 && newCol >= 0 &&
                    mat[newRow][newCol] == 1 && visited[newRow][newCol] != 1) {
                    visited[newRow][newCol] = 1;
                    q.push({{newRow, newCol}, step + 1});
                }
            }
        }
        return ans;
    }
};