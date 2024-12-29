// Dijkstras fail for negative edges graph
// shorter oath may exist in longer route through negative edges

#include<bits/stdc++.h>
using namespace std;


class graph{
    int v;
    vector<vector<pair<int, int>>> adjList; 
    
    public:   

    graph(int ver){
        v = ver;
        adjList.resize(v);
    }


    void addEdge(int x, int y, int wt){
        adjList[x].push_back({wt, y});
        // adjList[y].push_back({wt, x});
    }

    void bellmanFord(int src, int dest, int e){
        vector<int> dis(v, INT_MAX);
        dis[src]=0;

        //relax edges v-1 times
        for(int i=0;i<v-1;i++){
            for(int u=0;u<v;u++){
                for(auto [weight, neighbour]: adjList[u]){
                    
                    if(dis[u]!=INT_MAX && dis[u]+weight<dis[neighbour]){
                        dis[neighbour] = dis[u]+weight;
                    }
                }
            }
        }

        // Check for negative-weight cycles
        for (int u = 0; u < v; u++) {
            for (auto &[weight, neighbor] : adjList[u]) {
                if (dis[u] != INT_MAX && dis[u] + weight < dis[neighbor]) {
                    cout << "Graph contains a negative-weight cycle" << endl;
                    return;
                }
            }
        }

        //print distances 
        for (int i = 0; i < v; i++) {
            cout << src << " -> " << i << " : ";
            if (dis[i] == INT_MAX)
                cout << "Infinity" << endl;
            else
                cout << dis[i] << endl;
        }
        return;
    }

};

int main(){
    graph g(5);
    g.addEdge(0,1,-1);
	g.addEdge(0,2,4);
	g.addEdge(1,2,3);
	g.addEdge(1,3,2);
	g.addEdge(1,4,2);
	g.addEdge(3,2,5);
	// g.addEdge(3,1,1);
	g.addEdge(4,3,-3);

    /*
       -1    2
    0---->1--->4
    |    /|   /
 4  |  3/ |  /-3
    |  / 2| /
    $ $   $$
    2<----3
       5
    */
    
    int edges = 8;

    g.bellmanFord(0,4, edges);

    cout<<"\n_____________________________\n";
    return 0;
}                                        