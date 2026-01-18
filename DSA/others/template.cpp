#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMax(vector<int> nums, int k, int i){
        cout<<i;
        
        if(i>=nums.size()) return 0;
        cout<<"-"<<i<<endl;

        if(i==nums.size()-1) return nums[i];
        
        int maxx=0;
        for(int t=1;t<=k;t++){
            maxx = max(maxx, findMax(nums, k, t+i));
        }
        cout<<"\nlol\n";
        return maxx+nums[i];
    }
    
    int maxResult(vector<int>& nums, int k) {
        return findMax(nums, k, 0);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> kk={1,-1,-2,4,-7,3};
    cout<<s.maxResult(kk,3);
    cout<<"\n__________\n";
    return 0;
}
