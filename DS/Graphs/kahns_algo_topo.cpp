/*

topological sort : liner ordering of vertices of 
directed acyclic graph(DAG) such that every directed edge u->v,
node u appears before v

indegree -> number of incoming edges to a node


    5 ->  0 <- 4
    |          |
    \/        \/
    2 -> 3 -> 1

    indegree : 

    0 1 2 3 4 5  (nodes)
    2 2 1 1 0 0

    -> insert all nodes with zero indegree (4,5) in queue

    -> remove the edge from queue, remove its edges from indegree array,
    insert 0 edge node back in queue

    TC: O(V+E)



    KHANS ALGO for cycle search
    -> if cycle is present, one of the node will never have indegree of 0,
    and will never be added to queue
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> topologicalSortKahn(vector<vector<int>> &graph, int n){

    vector<int> indegree(n, 0);
    for(auto x: graph){
        for(auto y: x){
            indegree[y]++;
        }
    }

    queue<int> qu;

    for(int i=0;i<n;i++){
        if(indegree[i]==0)
            qu.push(i);
    }

    vector<int> ans;
    while(!qu.empty()){
        int topNode = qu.front();
        ans.push_back(topNode);
        qu.pop();

        for(auto x: graph[topNode]){
            indegree[x]--;
            if(indegree[x]==0){
                qu.push(x);
            }
        }
    }

    if(ans.size()!=n) cout<<"cycle present!!\n";

    return ans;
}


void dfsHelper(vector<vector<int>> &graph, vector<bool> &visited, int i, stack<int> &dfsCompleted){
    visited[i]=true;

    for(auto nbr: graph[i]){
        if(!visited[nbr]){
            dfsHelper(graph, visited, nbr, dfsCompleted);
        }
    }

    dfsCompleted.push(i);
}

vector<int> topologicalSortDFS(vector<vector<int>> &graph, int n){
    vector<bool> visited(n, false);
    stack<int> dfsCompleted;

    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfsHelper(graph, visited, i, dfsCompleted);
        }
    }

    vector<int> ans;
    while(!dfsCompleted.empty()){
        ans.push_back(dfsCompleted.top());
        dfsCompleted.pop();
    }

    return ans;
}

int main()
{
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

    vector<vector<int>> graph(n);

    for(auto x: edges){
        graph[x[0]].push_back(x[1]);
    }

    vector<int> topo = topologicalSortKahn(graph, n);
    for(auto x: topo){
        cout<<x<<", ";
    }

    cout<<endl;

    vector<int> topo2 = topologicalSortDFS(graph, n);
    for(auto x: topo2){
        cout<<x<<", ";
    }

    cout<<"\n________\n";
}