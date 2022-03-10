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
    for(int i=0;i<nodes+1;i++){
        for(int j=0;j<graph[i].size();j++)
            cout<<graph[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}
/*
adjacency list
  1->2,3
  2->1,4
  3->1,4
  4->3,2
*/

 /*
Input
4 4
1 2  
1 3  
3 4
4 2
Output
2 3 
1 4 
1 4 
3 2
*/