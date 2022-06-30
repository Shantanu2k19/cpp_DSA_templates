#include<iostream>
using namespace std;

int knapsack(int wts[], int prices[], int N, int W){
    if(N==0||W==0) return 0;

    int inc=0, exc=0;

    if(wts[N-1]<=W){
        inc = prices[N-1] + knapsack(wts, prices, N-1, W-wts[N-1]);
    }
    exc = knapsack(wts, prices, N-1, W);
    return max(inc,exc);
}

int botomUpDP(int wts[], int prices[], int N, int W){
    int dp[100][100]={0};

    for(int i=0;i<=N;i++){
        for(int w=0;w<=W;w++){
            if(i==0 || w==0) dp[i][w]=0;
            else{
                int inc=0, exc=0;
                if(wts[i-1]<=w) //if weight of selected obj is less than required weight from loop 
                    inc = prices[i-1]+dp[i-1][w-wts[i-1]];
                exc = dp[i-1][w];
                dp[i][w] = max(inc,exc);
            }
        }
    }

    for(int i=0; i<=W+1;i++) if(i==0) cout<<"  "; else cout<<i-1<<" ";
    cout<<endl;
    for(int i=0;i<=N;i++){
        cout<<i<<" ";
        for(int j=0;j<=W;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    return dp[N][W];
}


int knapsackWithRepeat(int wts[], int prices[], int N, int W){
    if(N==0||W==0) return 0;

    int inc=0, exc=0;

    if(wts[N-1]<=W){
        inc = prices[N-1] + knapsack(wts, prices, N, W-wts[N-1]);  //here N-1 = N for repeat
    }
    exc = knapsack(wts, prices, N-1, W);
    return max(inc,exc);
}

int botomUpDPWithRepeat(int wts[], int prices[], int N, int W){
    int dp[100][100]={0};

    for(int i=0;i<=N;i++){
        for(int w=0;w<=W;w++){
            if(i==0 || w==0) dp[i][w]=0;
            else{
                int inc=0, exc=0;
                if(wts[i-1]<=w) //if weight of selected obj is less than required weight from loop 
                    inc = prices[i-1]+dp[i][w-wts[i-1]]; //here dp[i-1], i only for multiple
                exc = dp[i-1][w];
                dp[i][w] = max(inc,exc);
            }
        }
    }

    for(int i=0; i<=W+1;i++) if(i==0) cout<<"  "; else cout<<i-1<<" ";
    cout<<endl;
    for(int i=0;i<=N;i++){
        cout<<i<<" ";
        for(int j=0;j<=W;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    return dp[N][W];
}

int main(){
    int wts[] = {2,2,3,1};        //{2,7,3,4};
    int prices[] = {5,20, 100,30};     //{5,20,20,10};
    int N = 4;
    int W = 5;

    // int maxProfit = knapsack(wts, prices, N, W);   
    // cout<<maxProfit<<endl;
    // cout<<botomUpDP(wts, prices, N, W)<<endl;

    int maxProfit = knapsackWithRepeat(wts, prices, N, W);   
    cout<<maxProfit<<endl;
    cout<<botomUpDPWithRepeat(wts, prices, N, W)<<endl;

    cout<<"\n______________\n";
    return 0;
}