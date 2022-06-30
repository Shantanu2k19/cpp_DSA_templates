#include <bits/stdc++.h>
using namespace std;


vector<int>tree[5005]; // for storing tree in the form of adjacency list
set<int>ans; 
int n; // global declation of n so as to access easily


void subsetsum( vector<int>&child_size,vector<int>&subsets){
   // finding all possible subsets from child_sizes to partion it into two parts
    int x=child_size.size();

    vector<vector<int>>dp(x+1,vector<int>(n+1));

     dp[0][0]=1;
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            dp[i][j]=dp[i-1][j]; // leave ith element 
            if(j>=child_size[i-1])  // take the ith element if j>child_size[i-1]
             dp[i][j]= dp[i][j] || dp[i-1][j-child_size[i-1]];
        }
    }
  // removing the cases where each subtree is picked in one partion  
  // also removing case where no subtree is picked  
  //storing all possible subset sums in subsets vector

    for(int i=1;i<=n-2;i++){
        if(dp[x][i]==1){
        subsets.push_back(i);
      }
    }
}

int dfs(int node ,int parent){
    vector<int>child_size;
    vector<int>subsets;
    int res=0;
    for(auto i : tree[node]){
        if(i!=parent){// skipp if i is parent of node 
            int x=dfs(i,node);
            res=1;
            child_size.push_back(x);
        }
    }

    int sizesum=0;
    for(auto i : child_size){
        sizesum+=i;
    }
    if(res==0)return 1; // if node is a leaf node
    child_size.push_back(n-1-sizesum); // inserting size of remaining tree as a subtree
    subsetsum(child_size,subsets);
    for(int i=0;i<subsets.size();i++){
        ans.insert(subsets[i]);
    }
    return sizesum+1;
}


int32_t main(){


   cin>>n;

   for(int i=0;i<n-1;i++){
       int x,y;
       cin>>x>>y;
       tree[x].push_back(y);
       tree[y].push_back(x);
   }

    for(int i=1;i<n;i++){
        vector<int> lol;

        lol = tree[i];
        cout<<i<<"->";
        for(int j=0;j<lol.size(); j++){
            cout<<lol[j]<<" ";
        }
        cout<<endl;
    }

    cout<<"\n\n";

   dfs(1,0);  // traversing tree using depth first search

    cout<<ans.size()<<"\n";
    cout<<"\n_____________\n";
}