#include <iostream>
#include<queue>
#include<vector>
using namespace std ; 

class graph 
{
    public : 
    int no = 0;
    vector <string > list[10];
    string area [ 10];

    void addArea(string name)
    {
        area[no] = name ; 
        list[no].push_back(name);
        no ++ ; 
        cout<<"area added successfullt\n";
    }
    void display()
    {
        cout<<"Adjecency list is : "<<endl;
        for (int i = 0 ; i < no ; i++)
        {
            for (auto it : list[i])
            {
                cout<<" -> "<<it<<" ";
            }
            cout<<"\n";
        }
            cout<<"\n";

    }
    int getIndex(string name)
    {
        for (int i =0  ; i < no ; i++)
        {
            if (area[i]== name)
            {
                return i;
            }
        }
        return -1;
    }
    void addPath(string name1 , string name2)
    {
        int srcIndex = getIndex(name1);
        int destIndex = getIndex(name2);
        list[srcIndex].push_back(name2);
        list[destIndex].push_back(name1);//for directed graph it is commented
        cout<<"Path added succesfully \n";
    }

    void Bfs()
    {
        int visited [ 10] = {0} ;
        queue <string > q ; 
        visited[0] = 1 ; 
        q.push(area[0]);
        vector <string > ans ; 

        while (q.empty() == false)
        {
            string node_area = q.front() ; 
            q.pop() ; 
            // Push that node in BFS / ans ; 
            ans.push_back(node_area);
            // checking neighbours of that area/city through adjecency list 
            // for that we need index of that node_city/area
            int nodeIndex = getIndex(node_area);
            // Now traverse the ( adjecncy list / vector ) of that array ( ~ vector <int > array [ 10 ])

            for (auto it : list[nodeIndex])
            {
                // it : (~ area / city / adj list values)
                // again check if the area / city is visited ? if yes then dont push it (leave it ) : otherwise mark it as visited and push it in queue
                // for that thing we need its index ; 
                int index  = getIndex(it);
                if (visited[index] != 1)
                {
                    visited [ index] = 1 ; 
                    q.push(it);
                }
            }
        }
        // Displaying Breadth First Search
        for (auto it : ans)
        {
            cout<<"\t"<<it;
        }
        cout<<"\n";
    }
    void dfsCaller()
    {
        vector <string> ans ; 
        int dfsVisited [10] = { 1 }; 
        dfsVisited[0] = 1 ;  
        Dfs(area[0] , list , ans , dfsVisited  );

        for (auto it : ans)
        {
            cout<<it<<"\t";
        }
        cout<<"\n";
    }
    void Dfs(string node  ,  vector <string > adjList[] , vector <string> &ans , int visited[])
    {
        int nodeIndex = getIndex(node);
        visited[nodeIndex] = 1 ; 
        ans.push_back(node);

        for (auto it : adjList[nodeIndex] )
        {
            int itIndex = getIndex(it);
            if ( visited[itIndex] == false)
            {
                Dfs(it , adjList , ans  , visited);
            }
        }
    }

};

int main()
{
    graph g ; 
    g.addArea("malegaon"); // considering this root node
    g.addArea("nashik");
    g.addArea("mumbai");
    g.addArea("pune");
    g.addArea("nagpur");
    g.addArea("dhule");
    g.addArea("satara");
    g.addArea("goa");
    g.addArea("amravati");
    g.addArea("jalgaon");

    g.addPath("malegaon" , "nashik");
    g.addPath("nashik" , "mumbai");
    g.addPath("pune" , "satara");
    g.addPath("malegaon" , "pune");
    g.addPath("mumbai" , "goa");
    g.addPath("jalgaon" , "amravati");
    g.addPath("dhule" , "jalgaon");
    g.addPath("malegaon" , "dhule");
    g.addPath("amravati" , "nagpur");
    g.display();

    cout<<"--------------------\n";
    g.Bfs();
    cout<<"--------------------\n";
    g.dfsCaller();
    return 0;
}