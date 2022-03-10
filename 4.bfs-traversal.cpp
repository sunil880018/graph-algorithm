#include <bits/stdc++.h>
using namespace std;
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
            queue<int>q;
            q.push(i);
            vis[i]=true;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                cout<<node<<"\n";
                for(int n : graph[node]){
                    if(!vis[n]){
                        q.push(n);
                        vis[n]=true;
                    }
                }
            }
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
7
5
4
6

*/