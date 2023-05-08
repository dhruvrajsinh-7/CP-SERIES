#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    Node *left, *right;
};
Node *predecessor(Node *root, int key)
{
    Node *ans = NULL;
    while (root)
    {
        if (root->key < key)
        {
            ans = root;
            root = (root->right);
        }
        else
            root = root->left;
    }
    return ans;
}
Node *successor(Node *root, int key)
{
    Node *ans = NULL;
    while (root)
    {
        if (root->key > key)
        {
            ans = root;
            root = (root->left);
        }
        else
            root = root->right;
    }
    return ans;
}
void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    pre = predecessor(root, key);
    suc = successor(root, key);
}
int main()
{
    Node *root = new Node(50);
    root->left = new Node(30);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right = new Node(70);
    root->right->left = new Node(60);
    root->right->right = new Node(80);
    Node *pre = NULL, *suc = NULL;
    findPreSuc(root, pre, suc, 65);
    if (pre != NULL)
        cout << "Predecessor is " << pre->key << endl;
    else
        cout << "No Predecessor";
    if (suc != NULL)
        cout << "Successor is " << suc->key;
    else
        cout << "No Successor";
    return 0;
}