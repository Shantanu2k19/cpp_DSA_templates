#include<bits/stdc++.h>
using namespace std;

// class segTree
// {
//     public:
//     int sum;
//     segTree* left;
//     segTree* right;
//     int i;
//     int j;
//     segTree(int sm, int in, int jn)
//     {
//         i = in;
//         j = jn;
//         sum = sm;
//         left = NULL;
//         right = NULL;
//     }
// };

int constructHelper(int arr[], int start, int end, int* segTree, int curIndex)
{
    if(start==end)
    {
        segTree[curIndex] = arr[start];
    }

    int mid = start+(end-start)/2;
    segTree[curIndex] = constructHelper(arr, start,mid,segTree, curIndex*2+1)+constructHelper(arr,mid+1, end ,segTree, curIndex*2+2);
    return segTree[curIndex];
}

int* constructST(int arr[], int n)
{
    int x = (int)(ceil(log2(n)));  //height of tree
    int max_size = 2*(int)pow(2,x)-1;

    int* segTree = new int[max_size];

    constructHelper(arr, 0, n-1, segTree, 0);

    return segTree;
} 

void updateValueHelper(int* segTree, int start, int end, int i, int diff, int curIndex)
{
    if(i<start || i>end) return;

    segTree[curIndex] = segTree[curIndex]+diff;
    if(end!=start)
    {
        int mid = start+(end-start)/2;
        updateValueHelper(segTree, start, mid, i, diff, 2*curIndex+1);
        updateValueHelper(segTree, mid+1, end, i, diff, 2*curIndex+2);
    }
}

int getSumHelper(int* segTree, int start, int end, int sumStart, int sumEnd, int curIndex)
{
    if(sumStart<=start and sumEnd>=end) 
        return segTree[curIndex];

    if(end<sumStart || start>sumEnd) 
        return 0;

    int mid = start+(end-start)/2;

    return getSumHelper(segTree, start, mid, sumStart, sumEnd, 2*curIndex+1)+
        getSumHelper(segTree, mid+1, end, sumStart, sumEnd, 2*curIndex+2);
}

int getSum(int* segTree, int start, int end, int n)
{
    return getSumHelper(segTree, 0, n-1, start, end, 0);

}
void updateValue(int arr[], int* segTree, int n, int i, int new_val)
{
    int diff = new_val - arr[i];
    arr[i]=new_val;
    updateValueHelper(segTree, 0, n-1, i, diff,0);
}
int main(){
    int arr[] = {1,2,3,4,56,4,3,5,6};
    int n = sizeof(arr)/sizeof(int);

    int *segTree = constructST(arr,n);
    cout<<getSum(segTree, 0,4, n);



    cout<<"\n_________________\n";
}