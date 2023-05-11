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
void inorder(Node *root, vector<int> &v)
{
    if (root == NULL)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}
void makebst(Node *root, vector<int> &v, int &i)
{
    if (root == NULL)
        return;
    makebst(root->left, v, i);

    root->data = v[i++];

    makebst(root->right, v, i);
}
Node *binaryTreeToBST(Node *root)
{
    vector<int> v;
    int i = 0;
    inorder(root, v);
    sort(v.begin(), v.end());
    makebst(root, v, i);
    return root;
}
int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right = new Node(5);
    root->right->right = new Node(6);

    binaryTreeToBST(root);

    return 0;
}