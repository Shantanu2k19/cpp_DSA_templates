#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
int n;
int dp[10000][10000]; 
int sum(int s, int e){
    int ans = 0;
    for(int i=s;i<=e;i++){
        ans += arr[i];
        ans %= 100;
    }
    return ans;
}
int findSmoke(int i,int j){
    if(i>=j) return 0;

    if(dp[i][j]!=0){
        return dp[i][j];
    }

    dp[i][j]=INT_MAX;
    for(int k=i;k<j;k++){
        dp[i][j] = min(dp[i][j], findSmoke(i,k)+findSmoke(k+1,j)+sum(i,k)*sum(k+1,j));
    }
    return dp[i][j];
}

int main(){
    
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    

    memset(&dp[0][0], 0, sizeof(dp));
    cout<<findSmoke(0, n-1);

   // cout<<"\n____________\n";
}