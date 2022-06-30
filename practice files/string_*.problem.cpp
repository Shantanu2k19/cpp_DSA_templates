#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size() , m = p.size();
        vector<vector<bool> > dp(n+1 ,vector<bool>(m+1 , false));         
        dp[0][0] = true;          
        
        for(int i = 2; i<=m ; i+=2)
            if(p[i-1] == '*'){
                dp[0][i-1] = true;
                dp[0][i] = true;
            }
            else  break;
        
        for(int i = 1; i <=n; ++i)
            for(int j = 1; j <=m; ++j){
                if(p[j-1] != '*')
                    dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
                else{
                    char curr = p[j-2];
                    dp[i][j] = dp[i][j] || dp[i][j-2];
                    
                    if(curr == '.' || s[i-1] == curr)
                        dp[i][j] = dp[i][j] || dp[i-1][j];                    
                }
            }
        return dp[n][m];
    }
};

int main(){
    Solution s;
    s.isMatch("aab","c*.a*b");

    cout<<"\n_____________________________\n";
}
