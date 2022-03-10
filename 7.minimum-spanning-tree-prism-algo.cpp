#include <bits/stdc++.h>
using namespace std;

/*
 1. minimum spanning tree , convert the graph into tree which has n nodes,n-1 edges 
    and has minimum weight
 2. every nodes reachable to every nodes
 3. minimum spanning trees can be multiple solutions but choose minimum total weight
*/

/*
 solution
 step-1. initial pick first node and mark that is part of mst.
 step-2. traverse all the adjacent nodes, store their weights and their parents 
         which is not the part of mst.
 step-3. pick the minimum weight from all the adjacent edges of all the nodes of the mst.
 step-4. include the minimum edge into mst and mark as true.(from step-3)
*/
int main() {

    // undirected graph
    int nodes ,edges;
    cin>>nodes>>edges;

    vector<pair<int,int>>graph[nodes+1]; 

    for(int i=0;i<edges;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        graph[u].push_back({v,wt});
        graph[v].push_back({u,wt});
    }
    vector<int>weight(nodes+1,INT_MAX);
    vector<bool>mst(nodes+1,false);
    vector<int>parent(nodes+1,-1);

    priority_queue < pair<int,int>,vector<pair<int,int>>,greater <pair<int,int>> > pq; // min-heap

    weight[0] = 0;
    parent[0] = -1;
    pq.push({0,0}); // {weight,node} initially

    for(int i=1;i<nodes;i++){ // traverse n-1 edges

        int u = pq.top().second;
        pq.pop();
        mst[u]=true;

        for(auto n : graph[u]){ // taking adjacent nodes
            int node = n.first;
            int w = n.second;
            if(!mst[node] && w < weight[node]){ // agar mst ka part nahi h
                weight[node] = w; // store weight
                parent[node] = u; // store parent
                pq.push({w,node});
            }
        }
    }
    for(int i=0;i<nodes+1;i++){
        cout<<weight[i]<<" ";
    }
    return 0;
}

/*
input

5 6 (nodes,edges)
0 1 2 (edges,weight)
1 2 3
0 3 6
1 3 8
1 4 5
2 4 7

*/

/*
 output
  0 2 3 6 5
*/