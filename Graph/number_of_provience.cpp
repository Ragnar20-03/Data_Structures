class Solution {
    private : 
    void dfs(int start , int visited[] , vector<int> adj[])
    {
        visited[start] = 1 ; 
        for (auto it : adj[start])
        {
            if (visited[it] != 1 )
            {
                dfs(it , visited , adj );
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v =  isConnected.size() ;
        vector <int> adj [v];
        for (int i = 0 ; i < v ; i++ )
        {
            for (int j = 0 ; j< v; j ++)
            {
                if (isConnected[i][j] == 1 && i != j )
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int visited[200] = { 0 };
        int iCnt = 0 ;   

        for (int i = 0 ; i< v ; i++)
        {
            if (visited[i] != 1 )
            {
                iCnt++;
                dfs(i , visited , adj );
            }
        }
        return iCnt;
    }
};