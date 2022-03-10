#include <bits/stdc++.h>
using namespace std;

// if next adjacent node is visited and not equal to parent,means someone has visited already,that is called cycles
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

    vector<bool>vis(nodes+1,false);

    // making queue and store {node,parent}
    // initial parent will be -1
    
    
    for(int i=1;i<=nodes;i++){
        if(!vis[i]){
            queue<pair<int,int>>q;
            int parent = -1;
            q.push({i,parent});
            vis[i] = true;
            while(!q.empty()){
                pair<int,int> node = q.front();
                parent  = node.second;
                q.pop();
                for(auto n : graph[node.first]){
                    if(!vis[n]){
                        q.push({n,node.first});
                        vis[n]=true;
                    }else if(vis[n] && parent != n){
                        cout<<"cycle\n";
                    }
                }
            }
        }
    }
    return 0;
}




/*
input

11 10 number of nodes,number of edges
1 2
2 4
3 5
5 6
5 10
6 7
7 8
8 11
10 9
11 9

*/

// ouput 

/* cycle */