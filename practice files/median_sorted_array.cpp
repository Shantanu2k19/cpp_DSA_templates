#include<bits/stdc++.h>
using namespace std;

#define ll double
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size();
        int l2 = nums2.size();
        
        bool even;
        int target = l1+l2;
        if(target%2==0){
            even = true;
            target = target/2-1;
        }
        else{
            even = false;
             target = target/2;
        }

        cout<<l1<<" "<<l2<<" "<<even<<" "<<target<<endl;  //1 ,2 


        if(l1==0){
            if(even){
                ll lol = (nums2[target]+nums2[target+1]);
                return lol/2;
            }
            else return nums2[target];
        }
        if(l2==0){
            if(even){
                // cout<<nums1[target]<<", "<<nums1[target+1];
                ll lol = (nums1[target]+nums1[target+1]);
                return lol/2;
            }
            else return nums1[target];
        }

        
        ll i=0,j=0, curr=0, median=0;
        while(i<l1 && j<l2){
            cout<<"while";
            if(nums1[i]<nums2[j]){
                median = nums1[i];
                i++;
            }
            else{
                median = nums2[j];
                j++;
            }

            cout<<curr<<"-"<<median<<endl;

            if(curr==target){ //1 2   3 4
                if(even==false) return median;
                else{
                    ll temp;
                    if(i==l1){
                        temp = nums2[j];
                    }
                    else if(j==l2){
                        temp = nums1[i];
                    }                    
                    else if(nums1[i]<nums2[j]){
                        temp = nums1[i];
                    }
                    else{
                        temp = nums2[j];
                    }
                    return (median+temp)/2;
                }
            }
            curr++;
        }
        cout<<endl;
        
        while(i<l1){
            cout<<"++"<<i;
            median = nums1[i];
            if(curr==target){
                cout<<"yes";
                if(even == false) return median;
                else{
                    cout<<median;
                    median += nums1[i+1];

                    return median/2;
                }
            }
            i++;
            curr++;
        }
        
        while(j<l2){
            median = nums2[j];
            if(curr==target){
                if(even = false) return median;
                else{
                    median += nums2[j+1];
                    return median;
                }
            }
            j++;
            curr++;
        }
        
        return 0;
    }


    double findMedianSortedArraysBINARYSEARCH(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() < nums1.size()) return findMedianSortedArrays(nums2, nums1);
        int n1 = nums1.size();
        int n2 = nums2.size(); 
        int low = 0, high = n1;
        
        while(low <= high) {
            int cut1 = (low+high) >> 1;
            int cut2 = (n1 + n2 + 1) / 2 - cut1; 
            
        
            int left1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
            int left2 = cut2 == 0 ? INT_MIN : nums2[cut2-1]; 
            
            int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            int right2 = cut2 == n2 ? INT_MAX : nums2[cut2]; 
            
            
            if(left1 <= right2 && left2 <= right1) {
                if( (n1 + n2) % 2 == 0 ) 
                    return (max(left1, left2) + min(right1, right2)) / 2.0; 
                else 
                    return max(left1, left2); 
            }
            else if(left1 > right2) {
                high = cut1 - 1; 
            }
            else {
                low = cut1 + 1; 
            }
        }
        return 0.0; 
    }
};

int main(){
    vector<int> arr{2,2,2};
    vector<int> arr2{2};
    Solution gg;
    double jj = gg.findMedianSortedArrays(arr,arr2);
    cout<<endl<<jj;
    cout<<"\n_____________________________\n";
}                                       