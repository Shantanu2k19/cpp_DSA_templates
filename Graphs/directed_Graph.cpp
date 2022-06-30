#include<bits/stdc++.h>
using namespace std;

class graph{
    int v;
    list<int>* adjList;

    public:
    graph(int vertices){
        this->v=vertices;
        adjList = new list<int>[v];
    }

    void addEdge(int x, int y){
        adjList[x].push_back(y);
    }

    bool dfs_cycle(int node,vector<bool> &visited, vector<bool> &stack){
        visited[node]=true;
        stack[node]=true;

        for(int nbr: adjList[node]){
            if(stack[nbr]==true) return true;  //if in stack, already visited

            else if(visited[nbr]==false){
                bool nbrFoundCycle = dfs_cycle(nbr, visited, stack);
                if(nbrFoundCycle) return true;
            }
        }
        stack[node]=false;
        return false;
    }

    bool contain_cycle(){
        vector<bool> visited(v, false);
        vector<bool> stack(v, false);

        for(int i=0;i<v;i++){
            if(!visited[i]){
                if(dfs_cycle(i,visited,stack)) return true;
            }
        }
        return false;
    }

};

int main(){
    graph g(3);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.contain_cycle()? cout<<"yes" : cout<<"no";

    cout<<"\n_____________________________\n";
}                                       