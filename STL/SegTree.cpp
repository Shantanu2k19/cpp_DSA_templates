#include<iostream>
#include<vector>
using namespace std;

class segTree
{
    public:
    int start, end;
    segTree* left;
    segTree* right;
    int sum;

    segTree(int st, int en)
    {
        start = st;
        end = en;
        left = NULL;
        right = NULL;
        sum=0;
    }
};

segTree* root = NULL;

segTree* buildTree(vector<int> nums, int st, int en)
{
    //base case
    if(st>en) return NULL;

    segTree* rt = new segTree(st,en);
    if(st==en)
    {
        rt->sum = nums[st];
    }
    else 
    {
        int mid = st+(en-st)/2;
        rt->left = buildTree(nums, st, mid);
        rt->right = buildTree(nums, mid+1, en);
        rt->sum = rt->left->sum + rt->right->sum;
    }
    return rt;
}

void update(segTree* rt, int pos, int val)
{
    if(rt->start == rt->end)
    {
        cout<<"updating "<<rt->start<<endl;
        //leaf node
        rt->sum = val;
    }
    else 
    {
        int mid = rt->start + (rt->end - rt->start)/2;

        if(pos <= mid) update(rt->left, pos, val);
        else update(rt->right, pos, val);

        rt->sum = rt->left->sum + rt->right->sum;
    }

}

int sumRange(segTree* rt, int st, int en)
{
    if(rt==NULL) 
    {
        cout<<"bull reached\n";
        return 0;
    }

    //node found 
    if(rt->start==st and rt->end==en) return rt->sum;

    int  mid = rt->start + (rt->end-rt->start)/2;

    if(en<=mid)
    {
        //move left
        return  sumRange(rt->left, st, en);
    }
    else if(st>=mid+1)
    {
        //move right 
        return sumRange(rt->right, st, en);
    }
    else 
    {
        return sumRange(rt->left, st, mid)+sumRange(rt->right, mid+1, en);
    }
}

vector<vector<segTree*>> lol(10);
void printTree(segTree* node, int i)
{
    if(node == NULL) return;

    lol[i].push_back(node);
    printTree(node->left, i+1);
    printTree(node->right, i+1);
    return;
}

void printTree2(segTree* node)
{
    if(node==NULL) return;

    printTree2(node->left);
    cout<<node->sum<<",";
    printTree2(node->right);
    return;
}

void printTree3()
{
    for(auto x:lol)
    {
        for(auto y: x)
        {
            cout<<y->sum<<"("<<y->start<<","<<y->end<<")\t"; 
        }
        cout<<endl;
    }
}

int main(){
    vector<int> arr={0,1,2,3,4};
    int n = arr.size()-1;
    root = buildTree(arr, 0, n);
    update(root, 2, 10);
    // printTree2(root);
    printTree(root, 0);
    printTree3();

    cout<<sumRange(root, 0,3);

    cout<<"\n_________________\n";
}