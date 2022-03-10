
/* bipartite graph that can be coloured using 2 colors such that 
   no two adjacent nodes have same color */ 

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
    vector<int>color(nodes+1,-1); // initially colors have -1 value

    for(int i=1;i<=nodes;i++){ // visiting all nodes one by one 
        if(color[i] == -1){
            queue<int>q;
            q.push(i);
            color[i]=1;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(auto n : graph[node]){
                    if(color[n] == -1){
                        color[n] = 1 - color[node];
                        q.push(n);
                    }else if(color[n] == color[node]){
                        cout<<"not bipartite"<<"\n";
                        return 0;
                    }
                }
            }

        }
    }
    return 0;
}

/*
input 
9 10 nodes,edges
7 1
1 2
2 3
3 8
1 6
6 5
5 4
4 3
4 9
9 3
*/