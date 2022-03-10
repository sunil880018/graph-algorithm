#include <bits/stdc++.h>
using namespace std;
int main() {
    int nodes ,edges;
    cin>>nodes>>edges;

    vector<pair<int,int>>graph[nodes+1]; 

    for(int i=0;i<edges;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        graph[u].push_back({v,wt});//node,weight
        graph[v].push_back({u,wt});
    }

    int source;

    cin>>source;

    priority_queue < pair<int,int>,vector<pair<int,int>>,greater <pair<int,int>> > pq;
    vector<int>dist(nodes+1,INT_MAX);

    dist[source] = 0;
    pq.push({0,source}); // dist,node


    while(!pq.empty()){
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto n: graph[node]){
            int u = n.first;
            int d = n.second;
            if(dist[u] > distance + d){
                dist[u] = distance + d;
                pq.push({dist[u],u});
            }
        }
    }
    
    cout<<"from "<<source<<"\n";
    for(int i=1;i<=nodes;i++){
        cout<<dist[i]<<" ";
    }
    return 0;
}

/*
input 
5 6 node,edges
1 2 2 edges,weight
2 5 5
1 4 1
4 3 3
2 3 4
3 5 1

1 source

output

from 1
0 2 4 1 5 
*/