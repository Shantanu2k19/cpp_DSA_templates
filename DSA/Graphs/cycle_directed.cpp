// cycle detection
// using dfs (path already visited)

#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
    int v;
    unordered_map<int, vector<int>> adjList;

    Graph(int num){
        this->v = num;
    }

    void makeGraph(vector<vector<int>> edges, bool bidir=false){
        for(auto edge: edges){
            adjList[edge[0]].push_back(edge[1]);
            if(bidir) adjList[edge[1]].push_back(edge[0]);
        }
    }

    bool dfsHelper(int currNode, vector<bool> &visited, vector<bool> &pathVisited){
        visited[currNode] = true;
        pathVisited[currNode] = true;

        for(int nbr: adjList[currNode]){
            if(pathVisited[nbr]) return true;
            
            if(!visited[nbr]){
                if(dfsHelper(nbr, visited, pathVisited)) return true;
            }
        }

        pathVisited[currNode] = false;
        return false;
    }

    bool detectCycle(){
        vector<bool> visited(v+1, false);
        vector<bool> pathVisited(v+1, false);
        
        for(int i=1;i<=v;i++){
            if(!visited[i] && dfsHelper(i, visited, pathVisited))
                return true;
        }
        return false;
    }

    bool cycleExistDfs(int i, int parent, vector<bool> &visited){
        visited[i]=true;

        for(auto nbr: adjList[i]){
            if(!visited[nbr]){
                if(cycleExistDfs(nbr, i, visited)) return true;
            }
            else if(nbr!=parent) return true;
        }
        return false;
    }

    bool detectCycleUndirected(){
        vector<bool> visited(v+1, false);
        
        for(int i=1;i<=v;i++){
            if(!visited[i] && cycleExistDfs(i, -1, visited)) return true;
        }
        return false;
    }
};

int main(){
    Graph g(4);
    vector<vector<int>> edges = {{1,4}, {2,4}, {3,1}, {3,2}};
    /*
    3->1->4
    |     ^
    |     |
    ->2---|
    */
    g.makeGraph(edges);
    cout<<g.detectCycle()<<endl;
    
    vector<vector<int>> edges2 = {{1,4}, {4,2}, {3,1}, {2,3}};
    /*
    3->1->4
    ^     |
    |     |
    --2<--|
    */
    Graph g2(4);
    g2.makeGraph(edges2, true);
    cout<<g2.detectCycleUndirected()<<endl;

    cout<<"\n______\n";
}
