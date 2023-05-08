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
int minValue(Node *root)
{
    // Code here
    Node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        root = root->left;
    }
    if (prev == NULL)
        return -1;
    return prev->data;
}
int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right = new Node(5);
    root->right->right = new Node(6);

    cout << minValue(root) << endl;
    return 0;
}