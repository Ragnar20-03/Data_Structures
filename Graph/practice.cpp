#include<iostream>
#include<vector>
#include<queue>
using namespace std ; 

class Graph
{
    public : 
    int no  ; 
    vector<string> cities ; 
    vector <string > adj [ 10 ]; 
    Graph()
    {
       no =  0 ; 
    }

    void AddCity(string name)
    {
        cities.push_back(name);
        adj[no].push_back(name);
        no ++ ; 
    }
    int getIndex(string name)
    {
        for (int i = 0 ; i< no ; i++)
        {
            if (cities[i] == name)
            {
                return i ; 
            }
        }
        return -1; 
    }

    void addPath(string name1 , string name2)
    {
        int srcIndex = getIndex(name1);
        int destIndex = getIndex(name2);
        adj[srcIndex].push_back(name2);
        adj[destIndex].push_back(name1);
        cout<<"path added scuucesfully1 \n";
    }

    void displayAdj()
    {
        for (int i  = 0 ; i< no ; i++)
        {
            for (auto it  : adj[i])
            {
                cout<<it<<"\t";
            }
            cout<<"\n";
        }
    }
    void bfs()
    {
        int visited[10] = { 0 }; 
        visited[0] = 1  ;
        queue<string> q ; 
        q.push(cities[0]);
        vector<string>ans;
        while (q.empty() != true)
        {
            string node = q.front() ; 
            ans.push_back(node);
            int nodeIndex = getIndex(node);
            q.pop() ; 
            for (auto it : adj[nodeIndex])
            {
                int itIndex = getIndex(it);
                if (visited[itIndex] != 1 )
                {
                    visited[itIndex] = 1 ; 
                    q.push(it);
                }
            }
        }
        for (auto it : ans)
        {
            cout<<it<<"\t";
        }
        cout<<"\n";
    }
    void dfsCaller()
    {
        vector<string>  ans ; 
        int visited[10] = { 0 }; 
        dfs(cities[0] , ans , visited);
        for (auto it : ans)
        {
            cout<<it<<"\t";
        }
        cout<<endl;

    }
    void dfs(string start , vector<string> & ans , int visited[] )
    {
        int startIndex = getIndex(start);
        visited[startIndex] = 1 ; 
        ans.push_back(start); 
        for (auto it : adj[startIndex])
        {
            int itIndex = getIndex(it); 
            if (visited[itIndex] != 1 )
            {
                visited[itIndex] = 1 ; 
                dfs(it , ans , visited  );
            }
        }
    }

    int numbeOfProvience( )
    {
        int visited [10 ] = { 0 } ; 
        vector<string > ans ; 
        int iCnt = 0 ; 
        for (int i = 0 ; i< 10 ; i++ )
        {
            int cityIndex = getIndex(cities[i]);
            if (visited[cityIndex] != 1 )
            {
                iCnt++;
                dfs(cities[i] ,ans , visited );
            }
        }
        return iCnt;
    }



};

void bfsIsland(int rowStart  , int colStart , int visited[] )

int main()
{

    Graph g ; 
    g.AddCity("malegaon");
    g.AddCity("nashik");
    g.AddCity("pune");
    g.AddCity("mumbai");
    g.AddCity("dhule");
    g.AddCity("nagpur");
    g.AddCity("abc");
    g.addPath("malegaon" , "nashik");
    // g.addPath("malegaon" , "dhule");
    g.addPath("dhule" , "nagpur");
    g.addPath("nashik" , "mumbai");
    g.addPath("nashik" , "pune");

    g.bfs();
    g.dfsCaller();

    cout<<g.numbeOfProvience();

    int arr[4][4] =   {
        {0, 0, 1, 1},
        {1, 0, 0, 0},
        {1, 0, 0, 0},
        {1, 0, 1, 1}
    };

    int visited[4][4] =   {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };


    return  0 ; 
}