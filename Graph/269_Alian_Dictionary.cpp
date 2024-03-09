/*
    Approach : 
    first create adj list according to alien dictionary 
    then apply toposort 
*/
class Solution{
    private : 
    void bfs()
    {

    }
    void dfs(int start , int visited [] , stack < int > & s , vector<int > adj [] )
    {
        visited[start] = 1 ; 
        for (auto it : adj[start] )
        {
            if (visited[it] != 1 )
            {
                dfs(it , visited , s , adj);
            }
        }
        s.push(start);
    }
    public:
    string findOrder(string dict[], int N, int k) {
        //code here
        vector<int > adj [ k ] ; // create adjec list which will be convert k alphabets into numbers 
        string s1 ,  s2 ; 
        int visited[26] = { 0 } ; 
        for (int i = 0 ; i < N -1  ; i++ )
        {
            s1 = dict[i] ; 
            s2 = dict[i+1 ]; 
            int length = min(s1.size() , s2.size() ) ; 
            for (int ptr = 0 ; ptr < length ; ptr++ )
            {
                if ( s1[ptr] != s2[ptr])
                {
                    // - 'a' because we store it into integer 
                    adj[s1[ptr] - 'a' ] .push_back(s2[ptr] - 'a' );
                    break ; // sequence got 
                }
            }
        }
        stack<int > s ;
        
        for (int i = 0 ; i < k ; i++ )
        {
            if (visited[i] != 1 )
            {
                dfs(i , visited , s , adj  );
            }
        }
        
        string ans  = "" ; 
        for ( ; s.empty() == false ; )
        {
            ans = ans + char(s.top() + 'a' );
            s.pop() ; 
        }
            return ans ; 
    }
};

////////////////
// BFS

class Solution{
    private : 
    vector<int >  bfsKahansAlgo(int n , vector<int > adj [] )
    {
        int indegree[n] = { 0 } ; 
        queue<int > q ; 
        vector<int > topoSort ; 
        for (int i = 0 ; i < n ; i++ )
        {
            for (auto it : adj[i])
            {
                indegree[it] ++ ; 
            }
        }
        
        for (int i = 0 ; i <  n ; i++ )
        {
            if (indegree[i] == 0 )
            {
                q.push(i);
            }
        }
        
        while (!q.empty() )
        {
            int node = q.front() ; 
            q.pop() ; 
            topoSort.push_back(node);
            
            for (auto it : adj[node])
            {
                indegree[it] -- ; 
                if (indegree[it] == 0 )
                {
                    q.push(it);
                }
            }
        }
        return topoSort;
    }
    public:
    string findOrder(string dict[], int N, int k) {
        //code here
        vector<int > adj [ k ] ; 
        string s1 , s2 ; 
        for (int i = 0 ; i < N - 1 ; i++ )
        {
            s1 = dict[i];
            s2 = dict[i+1];
            int len = min(s1.size() , s2.size());
            for (int ptr = 0 ; ptr < len ; ptr ++ )
            {
                if (s1[ptr] != s2[ptr])
                {
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                    break; 
                }
            }
        }
        vector<int > topoSort = bfsKahansAlgo( k , adj);
        string ans = "";
        
        for (int i = 0 ; i < k ; i++ )
        {
            ans = ans + char(topoSort[i] + 'a');
        }
        return ans ;
    }
};