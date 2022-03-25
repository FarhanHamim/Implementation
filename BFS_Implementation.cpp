#include<bits/stdc++.h>
using namespace std;

#define max 101 //defining max 
vector <int> graph[max]; //initializing vector

bool visited[max];
int distan[max];

void bfs(int source)
{
    queue<int> Q;

    visited[source] = 1; //initializing by visiting source
    distan[source] = 0;  // initializing distance as 0
    Q.push(source);  //pussing source node in queue

    while(!Q.empty()) // until the queue becomes empty
    {
        int node= Q.front(); // taking Queue's first element in node
        Q.pop(); // to remove or pop front element

        for(int i=0; i<graph[node].size(); i++) //to visit rest all adjacent node
        {
            int next= graph[node][i]; // taking every next element of node into next
            if(visited[next]==0) //we will work when not visited
            {
                visited[next] = 1;  //first initializing as visited
                distan[next]= distan[node]+1;  //updating distance (Distance is from where the value came)+1;
                Q.push(next); //pussing at queue
            }
        }
    }
}

int main()
{
    int nodes=7, edges=9; //nodes in the graph=7 and edges in the graph=9
    cout << "Nodes are: " << nodes << " Edges are: " << edges <<endl;

    for(int i=0; i<edges; i++)
    {
        //because of undirected graph from one index to another index edges connected
        //reading graph and pussing element
        graph[1].push_back(2); graph[2].push_back(1);
        graph[1].push_back(3); graph[3].push_back(1);
        graph[1].push_back(7); graph[7].push_back(1);
        graph[2].push_back(3); graph[3].push_back(2);
        graph[3].push_back(7); graph[7].push_back(3);
        graph[2].push_back(4); graph[4].push_back(2);
        graph[4].push_back(5); graph[5].push_back(4);
        graph[3].push_back(6); graph[6].push_back(3);
        graph[5].push_back(6); graph[6].push_back(5);
    }

    int source=1; //source initializing as 1

    bfs(source); //passing source in bfs

    cout << "From source node " << source << endl;
    for(int i=1; i<=nodes; i++) // iterating all nodes and printing
    {
        cout << "Distance of " << i << " is " << distan[i] << endl;
    }
}