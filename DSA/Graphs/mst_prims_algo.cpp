/*

prims algo for finding minimum spanning tree in a graph. 
MST -> 
MST is only defined for undirected graph 

spanning tree: 
    1. Subset of graph, connecting all the vertices
    2. contains no cycle

minimum ST:
    minimum total weight of all spanning trees
    The MST is unique if all edge weights are distinct.
    For a graph with V vertices, an MST contains exactly V−1 edges.
    Removing any edge from the MST disconnects the graph.

*/

#include<bits/stdc++.h>
using namespace std;

void primsAlgo(vector<vector<pair<int,int>>> &adj, int v){
    vector<bool> visited(v, false);
    priority_queue< vector<int>, vector<vector<int>>,greater<vector<int>> > pq;
    //starting with 0
    pq.push({0, 0, -1}); //weight, node, parent

    vector<vector<int>> msp;

    while(!pq.empty()){
        vector<int> tp = pq.top();
        pq.pop();

        int wt = tp[0];
        int node = tp[1];
        int par = tp[2];

        if(visited[node]) continue;

        if(par!=-1){
            msp.push_back({par, node, wt});
        }
        visited[node]=true;


        for(auto nbrPair: adj[node]){
            int nbr = nbrPair.first;
            int nbrDis = nbrPair.second;

            if(!visited[nbr]){
                pq.push({nbrDis, nbr, node});
            }
        }
    }

    for(auto x: msp){
        cout<<x[0]<<"->"<<x[1]<<"  : "<<x[2]<<endl;
    }

    return;
}

int main()
{
    int n = 5;
    vector<vector<pair<int, int>>> adj(n);

    vector<tuple<int, int, int>> edges = {
        {0, 1, 2}, {0, 2, 1}, {2, 1, 1}, {2, 4, 2}, {2, 3, 2}, {3, 4, 1}
    };

    /*
           2  
        0----1    4
        |   /    /|
      1 | 1/  2/  |1
        | /  /    |
        |/ /      |
        2---------3
             2
    */

    for(auto [a, b, dis]: edges){
        adj[a].push_back({b, dis});
        adj[b].push_back({a, dis});
    }

    primsAlgo(adj, n);

    cout<<"\n______\n";


}