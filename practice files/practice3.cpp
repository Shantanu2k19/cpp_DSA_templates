#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        set<int, greater<int>> lol;
        for(int i=0;i<stones.size();i++){
            lol.insert(stones[i]);
        }
        set<int>::iterator itr1,itr2;
        
        while(1){
            printSet(lol);
            
            if(lol.size()==0)
                return 0;
            if(lol.size()==1){
                return *lol.begin();
            }
            
            itr1=lol.begin();
            itr2=lol.begin();
            itr2++;
            
            lol.erase(itr1);
            lol.erase(itr2);
            
            if(*itr1>*itr2){
                lol.insert(*itr1-*itr2);
            }
            else if(*itr2>*itr1){
                lol.insert(*itr2-*itr1);
            }
        }
        return 69;
    }

    void printSet(set<int, greater<int>> lol){
        set<int >::iterator it;
        it=lol.begin();
        for(;it!=lol.end();it++){
            cout<<*it<<"-";
        }
        cout<<endl;
    }
};

void findMatrix(vector< vector<int>> lol, int k){
    const int r=lol.size();
    const int c=lol[0].size();
    cout<<r<<" "<<c<<endl;
    int dp[r+1][c+1] = {0};

    //fill(&dp[0][0],&dp[0][0]+sizeof(dp), 0);
    memset(&dp[0][0], 0, sizeof(dp));

    vector<int> first = lol[0];

    //1, 1, 3, 2, 4, 3, 2 },
    for(int i=0;i<c;i++){
        // cout<<first[i]<<" ";
        dp[1][i+1] = dp[1][i]+first[i];
    }

    for(int i=2;i<=r;i++){
        vector<int> curr;
        curr = lol[i-1];

        for(int j=1;j<=c;j++){
            dp[i][j] = dp[i-1][j]+dp[i][j-1]+curr[j-1]-dp[i-1][j-1];
        }
    }

    int n = r;
    int min_sum=INT_MAX;
    for(int n=r;n>=1;n--){
        for(int i=r;i>=0;i--){
            for(int j=c;j>=0;j--){
                int sum=INT_MIN;
                if(i-n>=0 && j-n>=0){
                    sum = dp[i][j]-dp[i][j-n]-dp[i-n][j]+dp[i-n][j-n];
                    min_sum = min(min_sum, sum);
                }
            }
        }
        if(min_sum <= k){
            cout<<n;
            return;
        }
    }

    cout<<endl;
    for(int i=0;i<r+1;i++){
        for(int j=0;j<c+1;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return; 
}

void findPath(vector< vector<int> > kk){
    int m = kk.size();
    int n = kk[0].size();

    cout<<m<<" "<<n<<endl;
    
    if(m<=1 && n<=1){
        cout<<"0";
        return;
    }


    int dp[m+1][n+1];
    memset(&dp[0][0],0, sizeof(dp));

    for(int i=1;i<=m;i++){
        vector<int> temp;
        temp = kk[i-1];

        for(int j=1;j<=n;j++){
            if(i==1 && j==1){
                if(temp[j-1]==1){
                    dp[i][j]=0;
                }
                else{
                    dp[i][j]=1;
                }
                continue;
            }

            if(i==1){
                if(temp[j-1]==1){
                    dp[i][j]==0;
                }
                else
                dp[i][j]=dp[i][j-1];
            } 
            else
            if(j==1){
                if(temp[j-1]==1){
                    dp[i][j]==0;
                }
                else
                dp[i][j] = dp[i-1][j];
            }
            else{
                if(temp[j-1]==1){
                    dp[i][j]==0;
                }
                else
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
    }
    cout<<dp[m][n]<<endl;


    for(int i=0;i<m+1;i++){
        // vector<int> temp;
        // temp = kk[i];
        for(int j=0;j<n+1;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}

//class c1;
// class c1{
//     public:
//     c1(){
//         cout<<"base of c1"<<endl;
//         // c.dis();
//     }
// }ll;
// class c3{
//     public:
//     c3(){
//         cout<<"base of c3"<<endl;
//         // c.dis();
//     }
// }kk;
// class c2{
//     string var="lol"; 
//     public:
//     c2(){
//         var = "base of c2";
//     }
//     void dis(){
//         cout<<var<<endl;
//     }
// }c;

int maxSubstring(string s, int maxLetters, int minSize, int maxSize){
    // map to count frequencies.
    unordered_map<string, int> m;
    // keep a count of max frequency found.
    int max_freq = 0;
    
    for (int i = 0; i < s.size() - minSize + 1; i++) {
        string temp = s.substr(i,minSize);
        // make a set and compare size to check unique
        // characters in substrings < maxLetters.
        unordered_set<char> st(temp.begin(), temp.end());
        if (st.size() <= maxLetters) {
            m[temp]++;
            max_freq = max(max_freq, m[temp]);
        }
    }
    return max_freq;
}

int dpOptimalGameStrat(int val[],int s, int e){
    if(s==e)  return val[s];
    if(s>e) return 0;

    int profitLeft = val[s]+ min(dpOptimalGameStrat(val, s+2,e), dpOptimalGameStrat(val, s+1,e-1) );
    int profitRight = val[e]+ min(dpOptimalGameStrat(val, s,e-2) , dpOptimalGameStrat(val,s+1,e-1));

    int maxProfit = max(profitLeft,profitRight);
    return maxProfit;
}

int gameStrat2(int val[],int s, int e){
    if(s==e)  return val[s];
    if(s>e) return 0;
    // 8, 15, 3, 7
    int profitLeft = val[s]+max(gameStrat2(val, s+3,e), gameStrat2(val, s+2,e-1));
    int profitRight = val[e]+max(gameStrat2(val, s+2,e-1), gameStrat2(val, s+1,e-2));

    int maxProfit = max(profitLeft,profitRight);
    return maxProfit;
}


int main(){ 
    // vector<int> arr{2,7,4,1,8,1};
    // Solution s;
    // cout<<s.lastStoneWeight(arr);

    // int arr[][100] = { { 1, 1, 3, 2, 4, 3, 2 },
    //                 { 1, 1, 3, 2, 4, 3, 2 },
    //                 { 1, 1, 3, 2, 4, 3, 2 } };
    // vector< vector<int>> lol;
    // for(int i=0;i<3;i++){
    //     vector<int> temp;
    //     for(int j=0;j<7;j++){
    //         temp.push_back(arr[i][j]);
    //     }
    //     lol.push_back(temp);
    // }
    // int k= 22;
    // findMatrix(lol, k);
    
    // vector< vector<int> > arr{{0,0,1,0}, {0,0,0,0}};
    // //vector< vector<int> > arr{{1,0}};
    // findPath(arr);

    //lol kk("haha", 12);
    // kk.name = "shan";
    // kk.age = 21;
    // kk.print(kk);
    //c1 objj;
    //  c.dis();

    // string str="aababcaab";
    // // cin>>str;
    // int min = 3;
    // int max = 4;
    // int maxLetter = 2;
    // maxSubstring(str, maxLetter, min, max);
    // //cout<<str.substr(0,4);

    int val[] = {8, 15, 3, 7, 43, 1, 7, 10, 6};
    int n = sizeof(val)/sizeof(val[0]);
    cout<<dpOptimalGameStrat(val,0,n-1)<<endl;
    cout<<gameStrat2(val,0,n-1);

    cout<<"\n____________________________________________________\n";
	return 0;
}