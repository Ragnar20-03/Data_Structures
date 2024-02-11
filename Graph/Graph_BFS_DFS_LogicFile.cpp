#include <iostream>
#include<vector>
#include<queue>
using namespace std ; 


void bfs(int numberOfNodes , vector <int> & adjList)
{
    int visited [numberOfNodes] = { 0 } ; 
    visited[ 0 ] = 1;  
    queue<int> q ;
    q.push(0);
    vector < int > bfsTraversal ; 

    while(q.empty()  == false)
    {
        int node = q.front() ;
        q.pop() ;
        bfsTraversal.push_back(node);

        for (auto it : adjList)
        {
            if (visited [ it] != 1 )
            {
                visited[it] = 1 ; 
                q.push(it);
            }
        }
    }
}


void Dfs(int startNode , vector <int > adjList[ ] , int visited [] , vector <int > & dfsTraversal)
{
    // First marked that depth node or starting node as 1 ; AND add it to ans ; 
    visited[startNode] = 1 ; 
    dfsTraversal.push_back(startNode) ; 

// Check for all its neighbours to go in depth ;
    for (auto it : adjList[startNode])
    {
        // check weather neigbour node is already visited or not ? if it is visited then do nothing : else marked it as visited and go in depth for current node neighbour
        if (visited[it] != 1) 
        {
            Dfs(it , adjList , visited , dfsTraversal);
        }
    }
}