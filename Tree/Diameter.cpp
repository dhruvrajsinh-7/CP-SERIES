#include <bits/stdc++.h>
using namespace std;
int res = 0;
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
} int helper(Node *root, int &mx)
{
    if (root == nullptr)
    {
        return 0;
    }
    int lh = helper(root->left, res);
    int rh = helper(root->right, res);
    int height = 1 + max(lh, rh);
    mx = max(mx, 1 + lh + rh);
    return height;
}
// Function to return the diameter of a Binary Tree.
int diameter(Node *root)
{
    // Your code here
    helper(root, res);
    return res;
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
    cout << diameter(root);
    return 0;
}