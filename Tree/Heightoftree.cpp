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
} int height(struct Node *node);
int height(struct Node *node)
{
    // code here
    if (node == 0)
    {
        return 0;
    }
    int left = height(node->left);
    int right = height(node->right);
    int ans = max(right, left) + 1;
    return ans;
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);
    cout << height(root);
    return 0;
}