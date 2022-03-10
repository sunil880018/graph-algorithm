#include <bits/stdc++.h>
using namespace std;

void dfs(int node , vector<int>graph[],bool vis[]){
     cout<<node<<"\n";
     vis[node] = true;
     for(int x : graph[node]){
         if(!vis[x]){
             dfs(x,graph,vis);
         }
     }
}
int main() {

    // undirected graph
    int nodes ,edges;
    cin>>nodes>>edges;

    vector<int>graph[nodes+1]; // adjacency list

    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bool vis[nodes+1]={false};
    
    for(int i=1;i<=nodes;i++){
        if(!vis[i]){
            dfs(i,graph,vis);
        }
    }
    return 0;
}
/*
Input
7 6 nodes , edges
1 2 
2 3
2 7
3 5
7 5
4 6

Output
1
2
3
5
7
4
6

*/