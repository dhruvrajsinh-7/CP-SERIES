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
void inorder(Node *root, unordered_set<int> &st)
{
    if (root == NULL)
        return;

    inorder(root->left, st);
    st.insert(root->data);
    inorder(root->right, st);
}
bool check(Node *root, unordered_set<int> &st)
{
    if (root == NULL)
        return false;

    if (root->left == NULL && root->right == NULL)
    {
        int tp = root->data;
        if (st.count(tp - 1) && st.count(tp + 1))
            return true;
    }
    return (check(root->left, st) || check(root->right, st));
}

bool isDeadEnd(Node *root)
{
    // Your code here
    unordered_set<int> st;
    st.insert(0);
    inorder(root, st);

    return check(root, st);
}
int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right = new Node(5);
    root->right->right = new Node(6);

    cout << isDeadEnd(root) << endl;
    return 0;
}