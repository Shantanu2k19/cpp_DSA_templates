#include<bits/stdc++.h>
using namespace std;
template<typename T>

class graph{
    map<T, list<T>> adjlist;

    public:
    graph(){}

    void addEdge(T x, T y, bool bidir=false){
        adjlist[x].push_back(y);
        if(bidir) adjlist[y].push_back(x);
    }

    void print(){
        for(auto x: adjlist){
            cout<<x.first<<"->";
            for(auto ele : x.second){
                cout<<ele<<",";
            }
            cout<<endl;
        }
    }

    void bfs(T src){
        map<T, int> visited;
        queue<T> q;

        q.push(src);
        visited[src]=true;

        while(!q.empty()){
            T node = q.front();
            q.pop();

            cout<<node<<",";
            for(T neighbour : adjlist[node]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour]= true;
                }
            }
        }
    }

    void dfs(T src){
        unordered_map<T, bool> visited;
        dfsHelper(src, visited);
    }

    void dfsHelper(T node, unordered_map<T, bool> &visited){
        visited[node]=true;

        cout<<node<<",";
        for(auto x : adjlist[node]){
            if(!visited[x]) dfsHelper(x, visited);
        }
    }
};


int main(){
    graph<int> g;
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(2,100);
    g.addEdge(2,200);
    
    g.print();
    cout<<"_________________\n";
    
    g.bfs(0);
    cout<<"\n_________________\n";

    g.dfs(0);
    cout<<"\n_________________\n";
}