#include<bits/stdc++.h>
using namespace std;


int findMax(vector<int> arr, int n, int l, int cnt){
    if(n>=l) return 0;
    int play, noPlay;
    if(cnt != 2){
        play = arr[n] + findMax(arr, n+1, l, cnt+1);
        noPlay = findMax(arr, n+1, l, 0);
    }
    else{
        return findMax(arr, n+1, l, 0);
    }
    return max(play, noPlay);
}

int dp[100005]={-1};
int findMaxDP(vector<int> arr, int n, int l, int cnt){
    cout<<n<<"-";
    if(dp[n]!=-1) return dp[n];

    int play, noPlay;
    if(cnt != 2){
        play = arr[n] + findMaxDP(arr, n+1, l, cnt+1);
        noPlay = findMaxDP(arr, n+1, l, 0);
    }
    else{
        return dp[n]=findMaxDP(arr, n+1, l, 0);
    }
    return dp[n] = max(play, noPlay);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int lol;
        cin>>lol;
        arr.push_back(lol);
    }
    int f=0;
    // cout<<findMax(arr,0,n,f)<<endl;
    // return 0;
    int kk = findMaxDP(arr, 0, n, f);
    cout<<endl;
    for(int i=0;i<n+1;i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl<<kk;
    cout<<"\n_____________________________\n";
}                                      