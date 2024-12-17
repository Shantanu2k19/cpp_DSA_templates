#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
    int v;
    unordered_map<int, vector<int>> adjList;

    Graph(int num){
        this->v = num;
    }

    void makeGraph(vector<vector<int>> edges){
        for(auto edge: edges){
            adjList[edge[0]].push_back(edge[1]);
        }
    }

    bool dfsHelper(int currNode, vector<bool> &visited, vector<bool> &pathVisited){
        visited[currNode] = true;
        pathVisited[currNode] = true;
        bool ans = false;
        for(int nbr: adjList[currNode]){
            if(pathVisited[nbr]) return true;
            
            if(!visited[nbr]){
                ans = ans || dfsHelper(nbr, visited, pathVisited);
            }
        }

        pathVisited[currNode] = false;
        return ans;
    }

    bool detectCycle(){
        for(int i=1;i<=v;i++){
            vector<bool> visited(v+1, false);
            vector<bool> pasthVis(v+1, false);
            if(dfsHelper(i, visited, pasthVis)) return true;
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
    // vector<vector<int>> edges = {{1,4}, {4,2}, {3,1}, {2,3}};
    /*

    3->1->4
    ^     |
    |     |
    --2<--|

    */
    g.makeGraph(edges);
    cout<<g.detectCycle()<<endl;
    cout<<"\n______\n";
}