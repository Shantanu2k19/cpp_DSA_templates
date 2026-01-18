class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        
        while(root!=NULL)
        {
            if(root->left!=NULL)
            {   
                TreeNode* left = root->left;
                TreeNode* curr = root->left;

                while(curr->right!=NULL) curr = curr->right;

                curr->right = root->right;  //morris traversal
                
                root->left = NULL;
                
                root->right = left;
            }
            root = root->right;
        }
    }
};


//https://leetcode.com/problems/flatten-binary-tree-to-linked-list/submissions/
//https://www.youtube.com/watch?v=NOKVBiJwkD0