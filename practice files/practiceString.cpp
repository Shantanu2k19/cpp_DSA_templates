#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int matchPattern(string str, string pattern, int i, int j){  //i=pattern, j=string

    if(i==-1 and j==-1) return 1;

    if(j==-1){
        for(int k=0;k<i;k++){
            if(pattern[k]!='*') return 0;
        }
        return 1;
    }

    if(i==-1) return 0;

    //dp
    if(dp[i][j]!=-1) return dp[i][j];

    if(pattern[i] == str[j] or pattern[i]=='?') return dp[i][j]=matchPattern(str, pattern, i-1,j-1);

    if(pattern[i]=='*'){
        int op1 = matchPattern(str, pattern, i-1, j);
        int op2 = matchPattern(str, pattern, i, j-1);
        return dp[i][j]=op1 or op2;
    }
    return dp[i][j]=0;
}

int main() {
    memset(&dp[0][0], -1, sizeof(dp));

	string str="baaabab", pattern="a*ab";
	// cin>>str>>pattern;

	cout<<matchPattern(str, pattern, pattern.length()-1, str.length()-1);
    cout<<endl;
    for(int i=0;i<pattern.length();i++){
        for(int j=0;j<str.length(); j++){
            if(dp[i][j]==1) cout<<" 1";
            else
            if(dp[i][j]==0) cout<<" 0";
            else
            cout<<"-1";
        }
        cout<<endl;
    }
    cout<<"\n________________\n";
	return 0;
}