#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return (temp);
}
Node *leastCommonAncestor(Node *root, int a, int b)
{
    if (!root)
        return NULL;
    if (root->data == a or root->data == b)
        return root;
    Node *l = leastCommonAncestor(root->left, a, b);
    Node *r = leastCommonAncestor(root->right, a, b);

    if (l and r)
        return root;
    if (l)
        return l;
    return r;
}
int solve(Node *root, int a)
{
    if (!root)
        return 0;
    if (root->data == a)
        return 1;
    int l = solve(root->left, a);
    int r = solve(root->right, a);
    if (!l and !r)
        return 0;
    if (!l)
        return r + 1;
    if (!r)
        return l + 1;
    int minVal = min(l, r);
    return minVal + 1;
}
int findDist(Node *root, int a, int b)
{
    // Your code here
    Node *lca = leastCommonAncestor(root, a, b);
    int x = solve(lca, a);
    int y = solve(lca, b);
    return (x + y - 2);
}
int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->left->left = newNode(4);
    root->right = newNode(3);
    root->right->left = newNode(2);
    root->right->left->left = newNode(4);
    root->right->right = newNode(4);
    cout << findDist(root, 4, 3);
    return 0;
}