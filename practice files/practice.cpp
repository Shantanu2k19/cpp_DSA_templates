//Implement data structure that performs insert, delete, search and getRandom() in O(1) time complexity. 
#include<bits/stdc++.h>
using namespace std;

#define N 1000

// DP 
int findChange(int arr[],int x, int n){
    if(x == 0) return 0;

    int ans = INT_MAX;

    for(int i=0;i<n;i++){
        if(x-arr[i]>=0){
            int smallerAns = findChange(arr, x-arr[i], n);
            if(smallerAns != INT_MAX){
                ans = min(ans, smallerAns+1);
            }
        }
    }
    return ans;
}

//top down approach 
int fibonacci(int n, int dp[]){
  
    if (n==0) {
        dp[0] = 0;
        return 0;
    }
    if (n==1) {
        dp[1] = 1;
        return 1;
    }
    
    if(dp[n]!=-1) return dp[n];
    dp[n] = fibonacci(n-1, dp)+fibonacci(n-2, dp);
    return dp[n];
}


//wine problem 
int dp[N][N];

int maxProfit(int price[], int s, int e, int y){
    if(dp[s][e]!= -1){
        return dp[s][e];
    }

    if(s==e){
        return price[s]*y;
    }

    int maxLeft = price[s]*y + maxProfit(price, s+1, e, y+1);
    int maxRight = price[e]*y + maxProfit(price, s, e-1, y+1);
    
    int ans = max(maxLeft, maxRight);

    dp[s][e] = ans;

    return ans;
}

int main(){

    //coin change problem 
    // int ind[] = {1,2,5,10,50,100,200};
    // int usd[] = {1,7,10};
    // int x = 10;
    // int dp[11];
    // for(int i=0;i<11;i++){
    //     dp[i]=-1;
    // }
    // int n = sizeof(usd)/sizeof(usd[0]);
   // cout<<findChange(usd, x, n); 

    // cout<<fibonacci(x,dp)<<endl;

    //wine problem

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            dp[i][j] = -1;
        }
    }

    int price[] = {2,4,6,2,5};
    int n = sizeof(price)/sizeof(price[0]);
   
    int y = 1;
    cout<<maxProfit(price,0,n-1,y)<<endl;
    
    cout<<"\n______________________\n";
}