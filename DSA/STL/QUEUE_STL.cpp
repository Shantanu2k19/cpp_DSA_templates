#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arrayNesting(vector<int> kk) {
        int gcount = 1;
    
        for(int i=0;i<kk.size();i++){
            vector<int> nums = kk;
            int count=0;
            int n=i;

            while(nums[n]!=-1){
                cout<<endl;
                count++;
                int temp = n;
                n = nums[n];
                nums[temp]=-1;
            }
            gcount = max(gcount, count);
        }
        return gcount;
    }
};

int main(){
    vector<int> n{5,4,0,3,1,6,2};//0,1,3, 4, 2
    
    Solution ss;
    cout<<ss.arrayNesting(n);
    // cout<<n[10];
    cout<<"\n________________________\n";
}



