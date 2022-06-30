#include<iostream>
using namespace std;


//recursion;
int maxProfit(int wts[], int prices[], int N, int W){
    if(N==0 || W==0){
        return 0;
    }

    int inc=0, exc=0;

    //Include
    if(wts[N-1]<=W){
        inc = prices[N-1]+maxProfit(wts, prices, N-1, W-wts[N-1]);
    }

    //exclude
    exc = 0 + maxProfit(wts, prices, N-1, W);

    return max(inc,exc);
}


//bottom up DP
// int wts[] = {2,7,3,4};
// int prices[] = {5,20,20,10};
int bottomUP(int wts[], int prices[], int N, int W){
    int dp[100][100] = {0};
    for(int i=0;i<=N;i++){
        for(int w=0;w<=W;w++){
            if(i==0 || w==0) dp[i][0]=0;
            else{
                int inc=0, exc=0;

                //including
                if(wts[i-1]<=w){
                    inc = prices[i-1]+dp[i-1][w-wts[i-1]];  
                }

                //excluding 
                exc = dp[i-1][w];

                dp[i][w]=max(inc,exc);
            }
        }
    }

    for(int i=0;i<=2;i++){
        for(int j=0;j<=W;j++){
            cout<<dp[i][j]<<"   ";
        }
        cout<<endl;
    }
    for(int i=3;i<=N;i++){
        for(int j=0;j<=W;j++){
            if(j<=2) 
                cout<<dp[i][j]<<"   ";
            else
                cout<<dp[i][j]<<"  ";
        }
        cout<<endl;
    }
    return dp[N][W];
}
int main(){
    int wts[] = {2,7,3,4};
    int prices[] = {5,20,20,10};
    int N=4, W=11;
    //cout<<maxProfit(wts, prices, N, W);
    cout<<bottomUP(wts,prices,N,W);
    cout<<"\n________________________\n";
}