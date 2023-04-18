#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
} void toSumTree(Node *node)
{
    // Your code here
    solve(node);
}
int solve(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    int left = solve(node->left);
    int right = solve(node->right);
    int val = node->data;
    node->data = left + right;
    return left + right + val;
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(-2);
    root->right = new Node(6);
    root->left->left = new Node(8);
    root->left->right = new Node(-4);
    root->right->left = new Node(7);
    root->right->right = new Node(5);
    toSumTree(root);
    cout << root->data << " " << root->left->data << " " << root->right->data << " " << root->left->left->data << " " << root->left->right->data << " " << root->right->left->data << " " << root->right->right->data;
    return 0;
}