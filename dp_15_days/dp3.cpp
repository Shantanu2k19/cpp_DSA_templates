#include<bits/stdc++.h>
using namespace std;
#define ll long long 

ll longestSubSeq(ll arr[], ll n){ 
	int lis[n]; 
	lis[0] = 1; 

	for (int i = 1; i < n; i++ ) { 
		lis[i] = 1; 
		for (int j = 0; j < i; j++ ) 
			if ( arr[i] > arr[j] && lis[i] < lis[j] + 1) 
				lis[i] = lis[j] + 1; 
	} 

	return *max_element(lis, lis+n); 
} 

int main(){
    ll n;
    cin>>n;

    ll arr[n];
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<longestSubSeq(arr, n);
}