// #include<bits/stdc++.h>
// using namespace std;

// int findSubset(string s, set<int> arr){
//     if(s.length()==0){
//         return 0;
//     }

//     if(s.length()==1){
//         if(arr.find(int(s[0]))!=arr.end()) return 1;
//         else return 0;
//     }

//     for(int i=0;i<s.length();i++){

//     }
// }

// int main(){
//     string s;
//     cin>>s;

//     int n;
//     cin>>n;

//     set<int> arr;

//     for(int i=0;i<n;i++){
//         int temp;
//         cin>>temp;
//         arr.insert(temp);
//     }

//     findSubset(s,arr);
// }


#include<bits/stdc++.h>
#define LL long long int
#define M 1000000007
#define reset(a) memset(a,0,sizeof(a))
#define rep(i,j,k) for(i=j;i<=k;++i)
#define per(i,j,k) for(i=j;i>=k;--i)
#define print(a,start,end) for(i=start;i<=end;++i) cout<<a[i];
#define endl "\n"
#define inf 100000000000000
LL pow(LL a,LL b,LL m){LL x=1,y=a;while(b > 0){if(b%2 == 1){x=(x*y);if(x>m) x%=m;}y = (y*y);if(y>m) y%=m;b /= 2;}return x%m;}
LL gcd(LL a,LL b){if(b==0) return a; else return gcd(b,a%b);}
LL gen(LL start,LL end){LL diff = end-start;LL temp = rand()%start;return temp+diff;}
using namespace std;
LL dp[1001][1024];
//dp[i][j] total sequences ending at i that have bitmask of j as the set forming elements
int main()
{
    ios_base::sync_with_stdio(0);
    int n,MASK=0,i,j;
    string x="12345677";
    
    int s[14];
    // cin>>x;
    x = ' ' + x;
    // cin>>n;
    n=2;
    rep(i,1,n)
        {
            cin>>s[i];
            MASK|=(1<<s[i]);
            cout<<MASK<<" ";
        }
    cout<<endl;
    dp[0][0] = 1;
    rep(i,1,x.length()-1)
        {
            //cout<<x[i]<<endl;
            dp[i][0] = 1;
            for(j=0;j<=1023;j++)
                {
                    dp[i][j|(1<<(x[i]-'0'))] += dp[i-1][j];
                }
        }
    LL ans = 0;
    rep(i,1,x.length()-1){
    rep(j,0,1023)
        {
            if((j&MASK)==MASK)
                {
                    ans = ans + dp[i][j];
                }
        }
    }
    cout<<ans;
    cout<<"\n_______\n";
}
