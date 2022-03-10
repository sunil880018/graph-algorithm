#include <bits/stdc++.h>
using namespace std;
int main() {
    // undirected graph
    
    int nodes ,edges;
    cin>>nodes>>edges;

    int graph[nodes+1][edges+1]; // adjacency matrix

    for(int i=0;i<nodes+1;i++){
        for(int j=0;j<nodes+1;j++)
            graph[i][j] = 0;
    }

    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    for(int i=0;i<nodes+1;i++){
        for(int j=0;j<nodes+1;j++)
            cout<<graph[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}

 /*
Input
4 4
1 2
1 3
3 4
4 2
Output
0 0 0 0 0 
0 0 1 1 0 
0 1 0 0 0 
0 1 0 0 1 
1 0 0 1 0 
*/