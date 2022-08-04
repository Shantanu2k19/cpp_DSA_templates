#include <bits/stdc++.h>
using namespace std;

int getSumUtil(int *segTree, int start, int end, int sumStart, int sumEnd, int currentIndex)
{
	if (sumStart <= start && sumEnd >= end)
		return segTree[currentIndex];

	// If segment of this node is outside the given range
	if (end < sumStart || start > sumEnd)
		return 0;

	// If a part of this segment overlaps with the given range
	int mid = start+(end-start)/2;
	return getSumUtil(segTree, start, mid, sumStart, sumEnd, 2*currentIndex+1) +
		getSumUtil(segTree, mid+1, end, sumStart, sumEnd, 2*currentIndex+2);
}

int getSum(int *segTree, int n, int sumStart, int sumEnd)
{
	return getSumUtil(segTree, 0, n-1, sumStart, sumEnd, 0);
}

void updateValueUtil(int *segTree, int start, int end, int i, int diff, int currentIndex)
{
	// Base Case: If the input index lies outside the range of
	// this segment
	if (i < start || i > end)
		return;

	// If the input index is in range of this node, then update
	// the value of the node and its children
	segTree[currentIndex] = segTree[currentIndex] + diff;
	if (end != start)
	{
		int mid = start+(end-start)/2;
		updateValueUtil(segTree, start, mid, i, diff, 2*currentIndex + 1);
		updateValueUtil(segTree, mid+1, end, i, diff, 2*currentIndex + 2);
	}
}

void updateValue(int arr[], int *segTree, int n, int i, int new_val)
{
	// Get the difference between new value and old value
	int diff = new_val - arr[i];

	// Update the value in array
	arr[i] = new_val;

	// Update the values of nodes in segment tree
	updateValueUtil(segTree, 0, n-1, i, diff, 0);
}


int constructSTUtil(int arr[], int start, int end, int *segTree, int currentIndex)
{
	if (start == end)
	{
		segTree[currentIndex] = arr[start];
		return arr[start];
	}

	int mid = start+(end-start)/2;   
	segTree[currentIndex] = constructSTUtil(arr, start, mid, segTree, currentIndex*2+1) + constructSTUtil(arr, mid+1, end, segTree, currentIndex*2+2);
	return segTree[currentIndex];
}


int *constructST(int arr[], int n)
{
	//Height of segment tree
	int x = (int)(ceil(log2(n)));

	//Maximum size of segment tree
	int max_size = 2*(int)pow(2, x) - 1;

	// Allocate memory
	int *segTree = new int[max_size];

	// Fill the allocated memory segTree
	constructSTUtil(arr, 0, n-1, segTree, 0);

	// Return the constructed segment tree
	for(int i=0;i<max_size;i++) cout<<segTree[i]<<",";
	cout<<endl;
	return segTree;
}

// Driver program to test above functions
int main()
{
	int arr[] = {1,3,5};
	int n = sizeof(arr)/sizeof(arr[0]);

	int *segTree = constructST(arr, n);
	cout<<"Sum of values in given range = "<<getSum(segTree, n, 0, 2)<<endl;

	// for(int i=0;i<2*n-1;i++) cout<<segTree[i]<<",";
	// cout<<endl;

	// Print sum of values in array from index 1 to 3
	// cout<<"Sum of values in given range = "<<getSum(segTree, n, 0, 3)<<endl;

	// Update: set arr[1] = 10 and update corresponding
	// segment tree nodes
	updateValue(arr, segTree, n, 1, 2);

	// Find sum after the value is updated
	cout<<"Updated sum of values in given range = "
			<<getSum(segTree, n, 0, 2)<<endl;
	return 0;
}