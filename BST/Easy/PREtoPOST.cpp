#include <bits/stdc++.h>
using namespace std;
int i = 0;
// Function that constructs BST from its preorder traversal.
Node *post_order(int pre[], int size)
{
    // code here
    i = 0;
    return helper(size, INT_MAX, pre);
}
Node *helper(int size, int range, int pre[])
{
    if (i == size || pre[i] > range)
    {
        return NULL;
    }
    Node *root = newNode(pre[i++]);
    root->left = helper(size, root->data, pre);
    root->right = helper(size, range, pre);
    return root;
}
int main()
{
}