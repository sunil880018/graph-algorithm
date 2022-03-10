/*
 topological sort -> linear ordering of vertices such that of there is an edge u->v,
 u appears before v in that ordering.
 topological sort apply directed acyclic graph only
*/

/*
 solutions

 step-1. count the indegree of all the nodes
 step-2. push all the nodes into the queue which has indegree 0
 step-3. traverse the node from the queue, store in topo vector, decrease the indegree of adjacent node,
         and check if indegree 0 , push into queue.
 step-4. Print topo vector.

*/
/*
 application of topological sort
 1. Cycle detection in Directed graph
 
*/

#include <bits/stdc++.h>
using namespace std;
int main() {

    // directed graph
    int nodes ,edges;
    cin>>nodes>>edges;

    vector<int>graph[nodes+1]; // adjacency list

    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
    }
    vector<int>indegree(nodes+1,0);

    for(int i=0;i<nodes;i++){
        for(auto n : graph[i]){
            indegree[n]++;
        }
    }

    queue<int>q;
    for(int i=0;i<nodes;i++){ // traversing indegree vector
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    vector<int>topo;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(auto adjacent_node : graph[node] ){
            indegree[adjacent_node]--;
            if(indegree[adjacent_node] == 0){
                q.push(adjacent_node);
            }
        }
    }
    for(int i=0;i<nodes;i++){
        cout<<topo[i]<<" ";
    }
    return 0;
}