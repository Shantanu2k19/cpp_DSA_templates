#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        data = d;
        left=NULL;
        right=NULL;
    }
};

node* constructTree(){
    int temp;
    cin>>temp;
    if(temp==-1) return NULL;

    node* root = new node(temp);
    root->left = constructTree();
    root->right = constructTree();
    return root;
}
int even=0;
int odd=0;
void printLevels(node* root,int k){
    if(root==NULL) return;

    if(k%2==0) even += root->data;
    else odd += root->data;

    printLevels(root->right,k-1);
    printLevels(root->left,k-1);
}

node* constructLevelOrder(int arr[], node* root, int s, int e){
    if(s<e){
        node* temp = new node(arr[s]);
        root = temp;
        root->left = constructLevelOrder(arr, root->left, s*2+1, e);
        root->right = constructLevelOrder(arr, root->right, s*2+2, e);
    }
    return root;
}

void printTree(node* root){
    if(root!=NULL){
        cout<<root->data<<" ";
        printTree(root->left);
        printTree(root->right);
        cout<<endl;
    }
}

int main(){
    // node* head = constructTree();
    int n;
    cin>>n;
    int arr[n];
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    // while(!cin.eof()){
    //     int temp;
    //     cin>>temp;
    //     cout<<temp;
    //     i++;
    // }

    node* head = constructLevelOrder(arr, head, 0, n);
    printTree(head);
    printLevels(head,0);
    cout<<even<<endl<<odd<<endl;
    // print(head);
    return 0;
}

/*
1 2 4 -1 -1 5 -1 -1 3 -1 -1 

10
1 2 3 4 5 6 6 6 6 6
*/