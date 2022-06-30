#include<bits/stdc++.h>
using namespace std;
#define ll int 

ll dp[1000];

int maximumSum(int val[], int n){
    for(int i=0;i<n;i++){
            cout<<i<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<val[i]<<" ";
    }
    cout<<"\n\n";
    //{7 ,2 ,1 ,8 ,3, 3, 6, 6};

    for(int i=0;i<n;i++){
        dp[i]=dp[i-1]+val[i]*i;
        cout<<dp[i]<<" ";
    }
    cout<<"\n\n";
    int max_=0;

    for(int i=0;i<n;i++){
        int temp = dp[i]-val[i-1]-val[i+1];
        cout<<temp<<" ";
        max_ = max(max_, temp);
    }
    return max_;
}

int main(){

    ll n=8;
    ll arry[1000]={7 ,2 ,1 ,8 ,3, 3, 6, 6};

    memset(&dp[0], 0, sizeof(dp));
    int max_ele = *max_element(arry, arry+n);
    int values[max_ele+1]={0};
    cout<<++max_ele<<endl;

    for(int i=0;i<=n;i++){
        values[arry[i]]+=1; 
    }
    // for(int i=0;i<=n;i++){
    //     values[i] *= i;
    // }
    
   cout<<"\n"<<maximumSum(values, max_ele);

    cout<<"\n\n_________________________\n";
}