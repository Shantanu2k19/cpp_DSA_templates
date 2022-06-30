//longest common substring 
#include<bits/stdc++.h>
using namespace std;

int lcs(string str1, string str2, int l1, int l2){
    if(l1 ==0 || l2==0){
        return 0;
    }

    if(str1[l1-1] == str2[l2-1]){
        return 1+lcs(str1,str2,l1-1,l2-1);
    }
    else{
        return max(lcs(str1,str2,l1,l2-1), lcs(str1,str2,l1-1,l2));
    }
}


int lcsUsingDP(string str1, string str2, int l1, int l2){
    int dp[l1+1][l2+1];
    memset(&dp[0][0], -1, sizeof(dp));

    // for(int i=0;i<=l1;i++){
    //     for(int j=0;j<=l2;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;

    for(int i=0;i<=l1;i++){
        for(int j=0;j<=l2;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else if(str1[i-1] == str2[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else{ //str1[i-1]!str2[j-1]
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    cout<<"    ";

    for(int j=0;j<=l2;j++){
        cout<<str2[j]<<" ";
    }
    cout<<endl;

    for(int i=0;i<=l1;i++){
        if(i==0) cout<<"  ";
        else
        cout<<str1[i-1]<<" ";
        for(int j=0;j<=l2;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    vector<char> ans;

    //finding the string 
    for(int i=l1,j=l2;i>=0,j>=0;){
        cout<<"("<<i<<","<<j<<")";
        if( (dp[i-1][j-1]==dp[i][j]-1) && (dp[i][j-1]==dp[i-1][j])) {
            cout<<" ->"<<str1[i-1]<<" ";
            ans.push_back(str1[i-1]);
            i--;
            j--;
        }
        else if(dp[i-1][j]<dp[i][j-1])  j--;
        else if(dp[i-1][j]>dp[i][j-1])  i--;
        else j--;

        cout<<endl;
    }
    cout<<endl;

    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i];
    }
    cout<<endl;

    return dp[l1][l2];
}

int main(){
    string str1="adebefcq",str2="ghaibkjc";
    //cin>>str1>>str2;
    int l1 = str1.length();
    int l2 = str2.length();
    // cout<<lcs(str1,str2,l1,l2);
    cout<<lcsUsingDP(str1,str2,l1,l2)<<endl;
    cout<<"\n_______________\n";
}



// 0 0 0 0 
// 0 1 1 1 
// 0 1 1 1 
// 0 1 2 2