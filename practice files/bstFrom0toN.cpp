#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// class Solution{
//     public:
//     vector<TreeNode*> generateTrees(int n) {
//         TreeNode* root=NULL;

//         int arr[10];

//         vector<TreeNode*> trees;
//         for(int i=0;i<n;i++){
            
//         }

//         int l = sizeof(arr)/sizeof(arr[1]);
//         for(int i=0;i<l;i++){
//             root = createTree(root, arr[i]);
//         }
//         cout<<"Tree created\n";
//         PrintTree(root);
//     }

//     TreeNode* createTree(TreeNode* root, int data){
//         if(root==NULL)  return new TreeNode(data);

//         if(data<=root->val) 
//             root->left = createTree(root->left, data);
//         else
//             root->right = createTree(root->right, data);
//         return root;
//     }

//     void PrintTree(TreeNode* root){
//         if(root==NULL) return;

//         cout<<root->val<<" ";
//         PrintTree(root->left);
//         PrintTree(root->right);
//         cout<<endl;
//     }

// };
 


class Solution {
public:
    vector<TreeNode*> rec(int start, int end) {
        vector<TreeNode*> res;
        if (start > end) return {NULL};
        
        if (start == end) return {new TreeNode(start)};
        
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> left = rec(start, i-1), right = rec(i+1, end);
            
            for (auto l : left)
                for (auto r : right)
                    res.push_back(new TreeNode(i, l, r));
        }
        return res;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res = rec(1, n);
        for(auto l:res){
            PrintTree(l);
            cout<<endl;
        }
        return res;
    }

    void PrintTree(TreeNode* root){
        if(root==NULL){
            cout<<"na "; 
            return;
        }

        cout<<root->val<<" ";
        PrintTree(root->left);
        PrintTree(root->right);
    }
};

int main(){
    Solution s;
    s.generateTrees(3);
    cout<<"\n_____________________________\n";
}                                       
