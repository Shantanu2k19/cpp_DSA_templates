// #include<bits/stdc++.h>
// using namespace std;

// #define vecp(a) for(int i=0;i<a.size();i++){ vector<int> temp; temp = a[i]; for(int j=0;j<temp.size(); j++) cout<<temp[j]<<" ";  cout<<endl; }
// #define ds cout<<"\n\n"

// int dp[100005][4];

// int optimalPrice(vector<vector<int>> prices, int level, int n, int prev){
//     if(level>=n) return 0;


//     int pp=INT_MAX;
//     for(int i=0;i<3;i++){

//         if(dp[level][i]!=-1) return dp[level][i];

//         vector<int> temp;
//         temp = prices[level];
//         if(i==prev) continue;
//         dp[level][i] = temp[i] + optimalPrice(prices, level+1, n, i);
//         pp = min(pp,dp[level][i]);
//     }
//     // return dp[level];
//     return pp;
// }

// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         memset(&dp[0][0], -1, sizeof(dp));
//         int n;
//         cin>>n;
//         vector<vector<int>> prices;
//         for(int i=0;i<n;i++){
                
//             vector<int> shop;
//             for(int j=0;j<3;j++){
//                 int temp;
//                 cin>>temp;
//                 shop.push_back(temp);
//             }
//             prices.push_back(shop);
//         }
//         // ds;
//         // vecp(prices);
//         // ds;
//         cout<<optimalPrice(prices, 0, n, -1)<<endl;
//         // cout<<dp[le/]
//         // cout<<endl;
//         // for(int i=0;i<n;i++){
//         //     for(int j=0;j<3;j++){
//         //         cout<<dp[i][j]<<" ";
//         //     }
//         //     cout<<endl;
//         // }
//     }
//     // cout<<"\n_____________________________\n";
// }                                       



// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minCost(int N, vector<int> cost[]) {
        // code here
        vector<vector<int>> dp(N+1,vector<int>(3,0));
        dp[1] = cost[0];
        for(int i = 1; i < N; i++) {
            for(int j = 0; j < 3; j++) {
                if(j == 0)       dp[i+1][0] = min(dp[i][1],dp[i][2]) + cost[i][0];
                else if(j == 1)  dp[i+1][1] = min(dp[i][0],dp[i][2]) + cost[i][1];
                else             dp[i+1][2] = min(dp[i][1],dp[i][0]) + cost[i][2];
            }
        }
        cout<<"\n\n";
        for(int i=0;i<=dp[0].size();i++){
            vector<int> temp = dp[i];
            for(int j=0;j<temp.size();j++){
                cout<<temp[j]<<" ";
            }
            cout<<endl;
        }
        return min(dp[N][0],min(dp[N][1],dp[N][2]));
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> cost[N];
        int x, y, z;
        for(int i = 0;i < N;i++){
            cin>>x>>y>>z;
            cost[i].push_back(x);
            cost[i].push_back(y);
            cost[i].push_back(z);
        }
        
        // for(int i=0;i<N;i++){
        //     for(int j=0;j<3;j++){
        //         cout<<cost[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
       Solution ob;
       cout<<ob.minCost(N, cost)<<"\n";
    }
    return 0;
}  // } Driver Code Ends