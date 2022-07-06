#include<bits/stdc++.h>
using namespace std;

class graph{
    int v;  // no of nodes in graph
    list<int> *l; //list<int> *l = new list<int>[v];

    public:
    graph(int val){
        v = val;
        l = new list<int>[v];
    }

    void addEdge(int i, int j, bool undir=true){ 
        l[i].push_back(j);
        if(undir){
            l[j].push_back(i);
        }
    }

    void bfs(int source){
        queue<int> q;
        bool *visited = new bool[v]{0};

        q.push(source);
        visited[source]=true;
        while(!q.empty()){
            int f = q.front();
            cout<<f<<"\n";
            q.pop();

            for(auto nbr: l[f]){
                if(!visited[nbr]) {
                    q.push(nbr);
                    visited[nbr]=true;
                }
            }
        }
    }

    void bfsDistance(int source, int dest=-1){
        //single source shortest path algo for undirected graph
        queue<int> q;
        bool *visited = new bool[v]{0};
        int *dist = new int[v]{0};
        int *parent = new int[v];

        for(int i=0;i<v;i++) parent[i]=-1;
        
        q.push(source);
        visited[source]=true;
        parent[source]=source;
        dist[source]=0;

        while(!q.empty()){
            int f = q.front();
            cout<<f<<"\n";
            q.pop();

            for(auto nbr: l[f]){
                if(!visited[nbr]) {
                    q.push(nbr);

                    parent[nbr]=f;
                    dist[nbr]=dist[f]+1;
                    visited[nbr]=true;
                }
            }
        }
        //print shortest node
        for(int i=0;i<v;i++){
            cout<<"shortest distance to "<<i<<" is "<<dist[i]<<endl;
        }
        //print path
        if(dest!=-1){
            int temp = dest;
            while(temp!=source){
                cout<<temp<<"->";
                temp=parent[temp];
            }
            cout<<source<<endl;
        }
    }

    void printAdjList(){
        for(int i=0;i<v;i++){
            cout<<i<<"->";
            for(auto itr: l[i]){
                cout<<itr<<",";
            }
            cout<<endl;
        }
    }

    void dfs(int source){
        bool *visited = new bool[v]{0};
        dfsHelper(source, visited);
    }

    void dfsHelper(int node, bool *visited){
        visited[node]=true;
        cout<<node<<",";
        for(int nbr: l[node]){
            if(!visited[nbr]) dfsHelper(nbr, visited);
        }
    }

    bool cycleDetection(int source){
        queue<int> q;
        map<int, bool> visited;
        map<int, int> parent;

        q.push(source);
        visited[source]=true;
        parent[source]=source;
        cout<<source<<" ";


/*

1--2  3--5--6
|      \ |
0--------4

*/             
        while(!q.empty()){
            int f = q.front();
            q.pop();
// 0-1-2-3
            for(auto nbr: l[f]){
                if(!visited[nbr]){
                    cout<<nbr<<" ";
                    q.push(nbr);
                    visited[nbr]=true;
                    parent[nbr]=f;
                }
                else{
                    if(parent[f]!=nbr && nbr!=source){
                        cout<<"\nfault -"<<nbr;
                        return false;
                    }
                }
            }
        }
        return true;
    }

    bool dfsCycleDetection(int node, vector<bool> &visited, int parent){
        visited[node]==true;
        cout<<"\nnode-"<<node<<"\n";

        for(auto nbr : l[node]){
            if(!visited[nbr]){
                cout<<nbr<<", ";
                bool foundCycle = dfsCycleDetection(nbr, visited, node);
                if(foundCycle) return true;
            }
            else{
                if(nbr!=parent) return true;
            }
        }
        return false;
    }

    bool contain_cycle_dfs(){
        vector<bool> visited(v,false);
        return dfsCycleDetection(0,visited,-1);
    }

};

int main(){
    graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,1);

    // g.addEdge(0,1);
    // g.addEdge(1,2);
    // g.addEdge(3,5);
    // g.addEdge(5,6);
    // g.addEdge(4,5);
    // g.addEdge(0,4);

    // g.addEdge(3,4);

    g.printAdjList();
    cout<<endl;

    // g.bfs(0);
    // g.bfsDistance(1,6);
    // g.dfs(0);
    // (g.cycleDetection(0))
    if(g.contain_cycle_dfs()) cout<<"\ncycle present";
    else cout<<"\nno cycle";
    
    
    cout<<"\n_____________________________\n";
} 

/*

1--2  3--5--6
|        |
0--------4

*/                   