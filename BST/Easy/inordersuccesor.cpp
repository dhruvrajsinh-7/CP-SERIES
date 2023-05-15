#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node *next;
};

Node *parent = NULL;
void dfs(Node *root)
{
    if (!root)
        return;

    dfs(root->right);

    root->next = parent;
    parent = root;
    dfs(root->left);
    return;
}
void populateNext(Node *root)
{
    dfs(root);
}
int main()
{
    Node *root = new Node();
    root->data = 10;
    root->left = new Node();
    root->left->data = 5;
    root->right = new Node();
    root->right->data = 15;
    root->left->left = new Node();
    root->left->left->data = 2;
    root->left->right = new Node();
    root->left->right->data = 7;
    root->right->left = new Node();
    root->right->left->data = 12;
    root->right->right = new Node();
    root->right->right->data = 20;
    populateNext(root);
    while (root)
    {
        cout << root->data << " ";
        root = root->next;
    }
    return 0;
}