#include<bits/stdc++.h>
using namespace std; 

 vector<int> topologicalSortKahn(vector<vector<int>> graph, int n){
    vector<int> indegree(n,0);

    for(auto x: graph){
        for(auto y: x){
            indegree[y]++;
        }
    }

    vector<int> ans;
    queue<int> qu;
    for(int i=0;i<n;i++){
        if(indegree[i]==0) qu.push(i);
    }

    while(!qu.empty()){
        int frnt = qu.front();
        qu.pop();
        ans.push_back(frnt);
        for(auto nbr: graph[frnt]){
            indegree[nbr]--;
            if(indegree[nbr]==0){
                qu.push(nbr);
            }
        }
    }
    return ans;
 }

 vector<int> topologicalSortDFS(vector<vector<int>> graph, int n){
    
 }

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