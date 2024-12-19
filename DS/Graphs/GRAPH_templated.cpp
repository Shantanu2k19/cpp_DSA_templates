#include<bits/stdc++.h>
using namespace std;
template<typename T>

class graph{
    //adj list
    map<T, list<T> > adjlist;
    
    public:
    graph() {}

    void addEdge(T x, T y, bool bidir=false){
        adjlist[x].push_back(y);
        if(bidir) adjlist[y].push_back(x);
    }

    void bfs(T src){
        map<T,int> visited;
        queue<T> q;

        q.push(src);
        visited[src]=true;

        while(!q.empty()){
            T node = q.front();
            q.pop();

            cout<<node<<"->";
            for(int neighbour: adjlist[node]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour]=true;
                }
            }
        }
    }

    void printAdjList(){
        for(auto itr: adjlist){
            cout<<itr.first<<"->";
            for(auto it: itr.second){
                cout<<it<<",";
            }
            cout<<endl;
        }
    }

    void dfs(int source){
        map<int, bool> visited;
        dfsHelper(source,visited);
    }

    void dfsHelper(int node, map<int, bool> &visited){
        visited[node]=true;
        cout<<node<<",";
        for(int nbr: adjlist[node]){
            if(!visited[nbr]){
                dfsHelper(nbr, visited);
            }
        }
        return;
    }

};

int main(){
    graph<int> h;
    h.addEdge(0,1);
    h.addEdge(0,3);
    h.addEdge(1,2);
    h.addEdge(2,3);
    h.addEdge(3,4);
    h.addEdge(4,5);
    h.addEdge(3,6);
    // h.printAdjList();
    // cout<<endl;
    // h.bfs(0);
    h.dfs(0);
    cout<<"\n_____________________________\n";
}
/*
    0-1-2
    |   |
    '---3----6
        |
        4
        |
        5
*/