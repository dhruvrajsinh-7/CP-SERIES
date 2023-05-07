#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

Node *prev = NULL;
Node *head = NULL;

Node *convertToDLL(Node *root)
{
    if (!root)
        return NULL;

    convertToDLL(root->left);

    if (!prev)
    {
        head = root;
    }
    else
    {
        prev->right = root;
        root->left = prev;
    }
    prev = root;

    convertToDLL(root->right);

    return head;
}

Node *binaryTreeToDLL(Node *root)
{
    Node *head = NULL;
    convertToDLL(root, head);
    return head;
}
int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Solution s;
    TreeNode *head = s.convertToDLL(root);

    while (head)
    {
        cout << head->val << " ";
        head = head->right;
    }

    return 0;
}
