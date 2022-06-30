// CPP program to Maximize the sum of selected
// numbers by deleting three consecutive numbers.
#include <bits/stdc++.h>
using namespace std;
 
// function to maximize the sum of selected numbers
int maximizeSum(int arr[], int n) {
 
    // Largest element in the array
    int mx = -1;
    for(int i = 0; i < n; i++)
    {
        mx = max(mx, arr[i]);
    }   
     
    // An array to count the occurence of each element
    int freq[mx + 1];
     
    memset(freq, 0, sizeof(freq));
     
    for(int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }
     
    // ans to store the result
    int ans = 0, i=mx;
     
    // Using the above mentioned approach
    while(i>0){
        for(int j = 0; j <= mx; j++) cout<<j<<" ";
        cout<<endl;
        for(int j = 0; j <= mx; j++) cout<<freq[j]<<" ";
        cout<<endl;
         
        // if occurence is greater than 0
        if(freq[i] > 0){
            // add it to ans
            ans += i;
             
            // decrease i-1th element by 1
            freq[i-1]--;
             
            // decrease ith element by 1
            freq[i]--;
        }else{
            // decrease i
            i--;
        }       

        cout<<ans<<endl;
    }
     
    return ans;
}
 
int max_sum_removing_elems(int arr[],int n,map<int,int> m,int start){
    if(start==n) {
    return 0;
    }

    int c1=INT_MIN;
    if(m[start]==0) {
    m[arr[start]-1]=1;
    m[arr[start]+1]=1;
    c1=arr[start]+max_sum_removing_elems(arr,n,m,start+1);
    }
    int c2=max_sum_removing_elems(arr,n,m,start+1);
    return max(c1,c2);
}

// Driver code
int main()
{
  int a[] = {1,2,3,5,5,6};
  int n = sizeof(a) / sizeof(a[0]);
  cout << maximizeSum(a, n);
  return 0;
}