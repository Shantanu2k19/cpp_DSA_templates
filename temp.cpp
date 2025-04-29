#include<bits/stdc++.h>
using namespace std; 


class Graph{
    public:
    int v;
    unordered_map<int, vector<int>> adjList;

    Graph(int v){
        this->v = v;
    }

    void addEdge(int src, int des){
        adjList[src].push_back(des);
        adjList[des].push_back(src);
    }

    bool cycleExistDfs(int i, vector<bool> &visited, vector<bool> &pathVis){
        visited[i]=true;    
        pathVis[i]=true;

        for(auto nbr: adjList[i]){
            if(pathVis[nbr]) return true;

            if(!visited[nbr]){
                if(cycleExistDfs(nbr, visited, pathVis)) return true;
            }
        }
        pathVis[i]=false;
        return false;
    }

    void detectCycle(){
        vector<bool> visited(v, false);
        vector<bool> pathVis(v, false);

        for(int i=0;i<v;i++){
            if(!visited[i] && cycleExistDfs(i, visited, pathVis)){
                cout<<"exist";
                return;
            }
        }
        cout<<"no cycle";
    }

};
int main(){
    vector<vector<int>> edges = {
        {5,0}, {5,2}, {4,0}, {4,1}, {2,3}, {3,1}
    };
    /*
            5-->0<--4
            |       |
            \/      \/
            2-->3-->1
    */
    int n = 6;

    Graph g(n);

    for(auto x: edges){
        g.addEdge(x[0], x[1]);
    }
    g.detectCycle();

    cout<<"\n________\n";
}