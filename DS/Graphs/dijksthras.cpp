#include<bits/stdc++.h>
using namespace std;

/*
TC:
O((V+E)logV)
V:vertices, E:edges

Inserting/updating elements in the priority queue takes O(logV).
Each vertex is processed once, and each edge is relaxed once.
*/

class graph{
    int v;
    list<pair<int, int>> *l; 
    
    public:   

    graph(int ver){
        v = ver;
        l = new list<pair<int,int> >[v];
    }

    void addEdge(int x, int y, int wt, bool undir=true){
        l[x].push_back({wt,y});
        if(undir) l[y].push_back({wt,x});
    }

    void printGraph(){
        for(int i=0;i<v;i++){
            cout<<i<<"-> ";
            for(auto ele: l[i]){
                cout<<ele.second<<"["<<ele.first<<"]"<<", ";
            }
            cout<<endl;
        }
    }
    
    int dijkstra(int src, int destination){
        vector<int> dist(v, INT_MAX);
        set< pair<int,int> > s;

        dist[src]=0;
        s.insert({0,src});

        while(!s.empty()){
            auto it = s.begin();
            int node = it->second;
            int distanceTillNow = it->first;
            s.erase(it);

            for(auto nbrPair : l[node]){

                int currentEdgeDist = nbrPair.first;
                int nbr = nbrPair.second;

                if(distanceTillNow+currentEdgeDist < dist[nbr]){
                    //remove if node already exist
                    auto f = s.find({dist[nbr], nbr});
                    if(f!=s.end()){
                        s.erase(f);
                    }

                    dist[nbr] = distanceTillNow+currentEdgeDist;
                    s.insert({dist[nbr], nbr});
                }
            }

        }
        //single source shortest path to all other nodes
        for(int i=0;i<v;i++){
            cout<<"Node "<<i<<", distance="<<dist[i]<<endl;
        }

        return dist[destination];
    }
    
    int dijkstrasWithPQ(int src, int destination){
        vector<int> distance(v, INT_MAX);
        distance[src]=0;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,src});

        while(!pq.empty()){
            int parNde = pq.top().second;
            int parDis = pq.top().first;
            pq.pop();
            if (parDis > distance[parNde]) {
                cout<<"skipping for"<<parNde<<endl;
                continue;
            }

            for(auto nbr: l[parNde]){
                int nbrNde = nbr.second;//weight first in adjList 
                int nbrDis = nbr.first;
                int newDis = parDis + nbrDis;

                if(newDis<distance[nbrNde]){
                    distance[nbrNde]=newDis;
                    pq.push({newDis, nbrNde});
                }
            }
        }
        //single source shortest path to all other nodes
        for(int i=0;i<v;i++){
            cout<<"Node "<<i<<", distance="<<distance[i]<<endl;
        }

        return distance[destination];
    }
};

int main(){
    graph g(5);
    g.addEdge(0,1,1);
	g.addEdge(1,2,1);
	g.addEdge(0,2,4);
	g.addEdge(0,3,7);
	g.addEdge(3,2,2);
	g.addEdge(3,4,3);

    g.printGraph();


    cout<<"set=>\n"<<g.dijkstra(0,4)<<endl;
    cout<<"pq=>\n"<<g.dijkstrasWithPQ(0,4)<<endl;

    cout<<"\n_____________________________\n";
    return 0;
}                                        