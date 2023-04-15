#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
int res = 1;

int helper(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = helper(root->left);
    int right = helper(root->right);
    if (abs(left - right) > 1)
    {
        res = 0;
    }
    return 1 + max(left, right);
}
// Function to check whether a binary tree is balanced or not.
bool isBalanced(Node *root)
{
    //  Your Code here
    helper(root);
    return res;
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(8);
    if (isBalanced(root))
        cout << "Balanced";
    else
        cout << "Not Balanced";
    return 0;
}