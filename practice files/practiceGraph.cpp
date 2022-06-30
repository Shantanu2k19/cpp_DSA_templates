#include<bits/stdc++.h>
using namespace std;

template<typename T>


class graph2{
    map<T, list<T>> adjlist;

    public: graph2(){}

    void addEdge(T u, T v, bool bidir=true){
        adjlist[u].push_back(v);
        if(bidir){
            adjlist[v].push_back(u);
        }
    }

    void print(){
        for(auto itr: adjlist){
            cout<<itr.first<<"->";
            for(auto rel:itr.second){
                cout<<rel<<",";
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

            cout<<node<<" ->";
            for(int neighbour:adjlist[node]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }

    void dfsHelper(T node, map<T, bool> visited){
        cout<<node<<"->";
        visited[node]=true;

        for(T neighbour: adjlist[node]){
            if(!visited[neighbour]){
                dfsHelper(neighbour, visited);
            }
        }
    }

    void dfs(T node){
        map<T, bool> visited;

        dfsHelper(node, visited);
    }


    int in[101], low[101], visited[101];
    int timer=0;

    void findBriges(T node, T parent){
        visited[node] = 1;
        in[node] = low[node] = timer; 
        timer++;
        for(int child: adjlist[node]){
            if(child == parent) continue;

            if(visited[child] == 1){
                //back edge 
                //minimise low time 
                low[node] = min(low[child], in[child]);
            }
            else{
                //forward edge
                findBriges(child,parent);

                if(low[child]>in[node])
                    cout<<node<<"-"<<child<<", is bridge\n";

                low[node] = min(low[node], low[child]);
            }
        }

    }
};


class graph{
    //unordered_
    map<string, list<pair<string,int>>> l;

    public:
    void addEdge(string x, string y, bool bidr, int wt){
        l[x].push_back(make_pair(y,wt));
        if(bidr){
            l[y].push_back(make_pair(x,wt));
        }
    }

    void printAdjList(){
        for(auto p:l){
            string city=p.first;
            list< pair<string,int> >neighbour = p.second;

            cout<<city<<"-> ";
            for(auto nbr: neighbour){
                string dest=nbr.first;
                int distance = nbr.second;

                cout<<dest<<" "<<distance<<", ";
            }
            cout<<endl;
        }
    }
};

int main(){
    graph g;
    g.addEdge("a","b",true,20);
    g.addEdge("b","d",true,40);
    g.addEdge("a","c",true,10);
    g.addEdge("c","d",true,40);
    g.addEdge("a","d",false,50);

    //g.printAdjList();


    graph2<int> g2;
    g2.addEdge(0,1);
    g2.addEdge(1,2);
    g2.addEdge(1,3);
    g2.addEdge(2,3);
    //g2.print();
    cout<<endl;
    g2.bfs(0);
    //cout<<endl;
    //g2.dfs(0);
    g2.findBriges(0,-1);
    cout<<"\n____________________\n";
}