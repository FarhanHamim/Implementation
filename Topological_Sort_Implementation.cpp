#include<bits/stdc++.h>
using namespace std;

vector <int> graph[101]; //initializing vector
bool visited[101];  //taking a array of declare visited or not

vector <int> result;

void dfs(int source) //passing source node to dfs 
{
    visited[source] = 1; //at first the called source node will initialize as visited 
    for(int i=0; i<graph[source].size(); i++)  //to check graph's source node index all element  
    {
        int next= graph[source][i];  //next will store element of source node
        if(visited[next]==0) //if next node of visited ==0 then recall dfs by next
        {
            dfs(next);
        }
    }
    //in this position all the chilldren of nodes is explored
    result.push_back(source); //now we can pushback result
}

int main()
{
    int nodes=5, edges=4; //nodes in the graph=5 and edges in the graph=4

    for(int i=0; i<edges; i++)
    {
        //pussing one way because it is directed graph
        graph[1].push_back(2);
        graph[3].push_back(2);
        graph[2].push_back(4);
        graph[2].push_back(5);
    }

    for(int i=1; i<=nodes; i++)
    {
        if(visited[i]==0)
        {
            dfs(i); //calling dfs, if any node not visited then we will call dfs by ith noded
        }
    }

    reverse(result.begin(), result.end()); //reversing result list with build in function

    cout << "Topological order is: ";
    for(int i=0; i<result.size(); i++)
    {
        cout << result[i] <<" "; //printing topological order after traversing
    }
    cout << endl;
}