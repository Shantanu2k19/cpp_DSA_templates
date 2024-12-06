#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
   vector<int> dfsOfGraph(vector<vector<int>>& adj) {

    stack<int> stk;
    stk.push(0);
    vector<int> ans;
    vector<int> visited(adj.size(), 0);

    while (!stk.empty()) {
        int node = stk.top();
        stk.pop();

        if(!visited[node]){
            ans.push_back(node);
            visited[node] = 1;
        }

        for (int i = adj[node].size() - 1; i >= 0; i--) {
            int chld = adj[node][i];
            if (visited[chld] == 0) {
                stk.push(chld);
            }
        }
    }

    return ans;
    };
};

int main(){
    // cout<<"hello world";
    vector<vector<int>> tc = {  
        {1,2,4,8},
        {0,5,6,9},
        {0,4},
        {7,8},
        {0,2},
        {1,8},
        {1,7,9},
        {3,6},
        {0,3,5},
        {1,6},
    };
    Solution g;
    vector<int> ans = g.dfsOfGraph(tc);
    cout<<"\nans: \t";
    for(auto x: ans){
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<"exp: \t"<<"0 1 5 8 3 7 6 9 2 4";
    cout<<"\n__________\n";
}