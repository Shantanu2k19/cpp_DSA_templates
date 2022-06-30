#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *constructTree()
{
    int d;
    cin >> d;
    if (d == -1)
    {
        return NULL;
    }

    node *root = new node(d);
    root->left = constructTree();
    root->right = constructTree();
    return root;
}

void bfs(node *root)
{
    if (root == NULL)
        return;

    queue<node *> qu;
    qu.push(root);
    qu.push(NULL);
    while (!qu.empty())
    {
        node *temp = qu.front();
        if (temp == NULL)
        {
            cout << endl;
            qu.pop();
            if (!qu.empty())
                qu.push(NULL);
        }
        else
        {
            cout << temp->data << " ";
            qu.pop();
            if (temp->left)
            {
                qu.push(temp->left);
            }
            if (temp->right)
            {
                qu.push(temp->right);
            }
        }
    }
}

void printTree(node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}

int main()
{
    //tree
    node *lol = constructTree();
    cout << endl;
    bfs(lol);
    //printTree(lol);

    cout << "\n___________________________\n";
}