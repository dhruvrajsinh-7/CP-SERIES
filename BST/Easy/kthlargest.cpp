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
void inorder(Node *root, int &k, int &ans)
{
    if (root == NULL)
        return;

    inorder(root->right, k, ans);

    k--;

    if (k == 0)
    {
        ans = root->data;

        return;
    }

    inorder(root->left, k, ans);
}

int kthLargest(Node *root, int k)
{
    int ans = 0;

    inorder(root, k, ans);

    return ans;
}
int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right = new Node(5);
    root->right->right = new Node(6);

    cout << kthLargest(root, 3) << endl;
    return 0;
}
