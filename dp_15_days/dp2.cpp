#include<bits/stdc++.h>
using namespace std;
#define ll long long 


ll n;
ll dp[1000][1000];
ll arry[1000];

ll findMax(ll s, ll e){
    if(s>e) return 0;

    if(s==e) return arry[s];

    if(dp[s][e]!=-1){
        return dp[s][e];
    }

    dp[s][e]=INT_MIN;
    for(ll k=s;k<=e;k++){
        dp[s][e] = max(dp[s][e], arry[k]+findMax(k+2,e)+findMax(s,k-2) );
    }
    return dp[s][e];
}

int main(){
    cin>>n;
    for(ll i=0;i<n;i++){
        ll temp;
        cin>>temp;
        arry[i] = temp;
    }
    memset(&dp[0][0], -1, sizeof(dp));
    cout<<findMax(0, n-1);

    // for(ll i=0;i<n;i++){
    //     for(ll j=0;j<n;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    //cout<<"success";
}