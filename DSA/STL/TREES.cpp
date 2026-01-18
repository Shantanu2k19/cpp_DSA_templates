#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right; 
    
    node(int d){
        this->left=NULL;
        this->right=NULL;
        this->data = d;
    };
};

/*
            1
      2          5
    3   4      6   7
                   2   3

    1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 7 2 -1 -1 3 -1 -1 
*/
node* makeTree(){
    int d;
    cin>>d;
    if(d==-1) return NULL;

    node* root = new node(d);
    root->left=makeTree();
    root->right=makeTree();
    return root;
}

void printTree(node* root){     //in order, root->l->r    1 2 3 -1 4 5 6 -1 -1 7 2 -1 -1 3 -1 -1
    if(root == NULL) return;

    cout<<root->data<<" ";
    printTree(root->left);
    printTree(root->right);
    cout<<endl;
}

class HBpair{
    public:
    bool isBal;
    int height; 
};

HBpair* check_height(node* root){
    HBpair p;
    if(root==NULL){
        p.isBal = false;
        p.height = 0;
    }
}

int heightOfTree(node* root){
    if(root==NULL) return 0;

    int lh = heightOfTree(root->left);
    int rh = heightOfTree(root->right);
    int height = max(lh,rh)+1;
    return height;
}

int noOfNodes(node* root){
    if(root == NULL) return 0;
    int n1 = noOfNodes(root->left);
    int n2 = noOfNodes(root->right);
    return (n1+n2+1);
}

int diameterOfTree(node* root){  //complexity O(n^2)
    if (root==NULL) return 0;

    //3 cases 
    //case1 : root node in diameter
    int h1 = heightOfTree(root->left);
    int h2 = heightOfTree(root->right);
    int op1 = h1+h2;

    //case2 : root in left branch 
    int op2 = diameterOfTree(root->left);

    //case3 : root in right branch 
    int op3 = diameterOfTree(root->right);

    return max(op1, max(op2,op3));
}

// Faster Diameter
// calculate height and diameter in traversal

class pairr{
    public:
    int height;
    int diameter;
};

pairr fastDiameter(node* root){
    pairr p;
    if(root == NULL){
        p.diameter = p.height = 0;
        return p;
    }

    pairr leftDia = fastDiameter(root->left);
    pairr rightDia = fastDiameter(root->right);

    p.height = max(leftDia.height,rightDia.height)+1;
    p.diameter = max( (leftDia.height+rightDia.height), max(leftDia.diameter,rightDia.diameter) );
    return p;
}

int elementTree(node* root){
    if(root==NULL) return 0;

    return elementTree(root->left)+elementTree(root->right)+1;
}

int main(){
    node* lol = makeTree();
    cout<<"\n\n";
    // printTree(lol);
    // cout<<"\nHeight of tree: "<<heightOfTree(lol)-1;
    // cout<<"\nNo of nodes: "<<noOfNodes(lol);
    // cout<<"\nDiameter of tree: "<<diameterOfTree(lol);
    // cout<<"\nDiameter fast: "<<fastDiameter(lol).diameter;
    cout<<elementTree(lol);
    cout<<"\n__________________________________\n";
    return (0);
}




//Footnotes

//diameter of tree : 3 cases: (1)passes through root node, (2)lies in left of root node, (3)lies in right of root node, 
//also : diameter = maximum number of continuous edges, not the nodes, height of left + right = diameter 
// no need to add 1, height addition compensates for it 

//height : max no of edges from root node to leaf node 

//FAST DIAMETER 
/* created a pair of height and diameter, hence in only once traversal, heights and diameter is calculated 
reduced complexity 
node from bottom returns height and diameter to top one 
*/


// while(root != NULL && root->val != val){
//             root = val<root->val? root->left:root->right;
//         }
//         return root;