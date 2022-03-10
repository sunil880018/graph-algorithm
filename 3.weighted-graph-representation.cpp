#include <bits/stdc++.h>
using namespace std;
int main() {
    int nodes ,edges;
    cin>>nodes>>edges;

    vector<pair<int,int>>graph[nodes+1]; // undirected weighted graph,store edge and coresponding weight

    for(int i=0;i<edges;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        graph[u].push_back({v,wt});
        graph[v].push_back({u,wt});
    }
    for(int i=0;i<nodes+1;i++){
        for(int j=0;j<graph[i].size();j++)
            cout<<"{"<<graph[i][j].first<<","<<graph[i][j].second<<"}"<<" ";
        cout<<"\n";
    }
    return 0;
}

 /*
Input

4 4
(edges,weight}
1 2 4
1 3 9
3 4 7
4 2 10

Output

{2,4} {3,9} 
{2,4} {2,10} 
{3,9} {4,7} 
{4,7} {2,10} 
*/