#include<bits/stdc++.h>
using namespace std;

vector <int> graph[5]; //initializing vector
bool visited[5];  //taking a array of declare visited or not

void dfs(int source) //passing source node to dfs
{
    visited[source] = 1; //at first the called source node will initialize as visited 
    cout << source << " "; //printing sources
    for(int i=0; i<graph[source].size(); i++)  //to check graph's source node index all element  
    {
        int next= graph[source][i];  //next will store element of source node
        if(visited[next]==0) //if next node of visited ==0 then recall dfs by next
        {
            dfs(next);
        }
    }
}

int main()
{
    int nodes=5, edges=4; //nodes in the graph=5 and edges in the graph=4
    cout << "Nodes are: " << nodes << " Edges are: " << edges <<endl;

    for(int i=0; i<edges; i++)
    {
        //reading graph and pussing element
        graph[0].push_back(1); graph[1].push_back(0);
        graph[1].push_back(2); graph[2].push_back(1);
        graph[1].push_back(3); graph[3].push_back(1);
        graph[3].push_back(4); graph[4].push_back(3);
    }

    int source=0; //source initializing as 1

    dfs(source); //passing source in bfs
    
    cout << endl << "From source node " << source << endl;
    for(int i=0; i<nodes; i++) // iterating all nodes and printing
    {
        if(visited[i]==1) 
        {
            cout << "Node " << i << " is visited" <<endl;
        }
        else
        {
            cout << "Node " << i << " is not visited" <<endl;
        }

    }
}