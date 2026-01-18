#include<iostream>
#include<vector>
using namespace std;

void updateBIT(int* BITree, int n, int index, int val){
    index += 1;

    while(index<=n){
        cout<<index<<",";
        BITree[index]+=val;
        index = index + ( index & (-index) );
    }
    cout<<endl;
}

int* constructBIT(vector<int> arr, int n)
{
    int *BITree = new int[n+1];
    for(int i=1;i<=n;i++){
        BITree[i]=0;
    }

    for(int i=0;i<n;i++){
        updateBIT(BITree, n, i, arr[i]);
    }

    return BITree;
}

int getSum(int* BITree, int index){
    int sum = 0;
    index += 1;

    while(index>0){
        sum += BITree[index];
        index = index - ( index&(-index) );
    }
    return sum;
}

int main()
{
    vector<int> freq = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9}; 
    int n = freq.size();
    int *BITree = constructBIT(freq, n);
    cout<<"sum of elements in arr[0..5] is : "<<getSum(BITree, 5)<<endl;

    updateBIT(BITree, n, 3, 6);

    cout<<"[After update] sum of elements in arr[0..5] is : "<<getSum(BITree, 5);

    cout<<"\n===\n";
    return 0;
}