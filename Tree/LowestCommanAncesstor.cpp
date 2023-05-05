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
bool helper(Node *root, vector<int> res, int target)
{
    if (root == nullptr)
    {
        return NULL;
    }
    res.push_back(root->data);
    if (root->data == target)
    {
        return true;
    }
    if (helper(root->left, res, target) || helper(root->right, res, target))
    {
        return true;
    }
    res.pop_back();
    return false;
}
int lcautil(Node *root, int n1, int n2)
{
    vector<int> res1, res2;
    if (!helper(root, res1, n1) || !helper(root, res2, n2))
    {
        return -1;
    }
    int i = 0;
    while (i < res1.size() && i < res2.size())
    {
        if (res1[i] != res2[i])
        {
            break;
        }
        i++;
    }
    return res1[i - 1];
}
Node *lca(Node *root, int n1, int n2)
{
    // Your code
    if (root == nullptr || root->data == n1 || root->data == n2)
    {
        return root;
    }

    Node *left_lca = lca(root->left, n1, n2);
    Node *right_lca = lca(root->right, n1, n2);

    if (left_lca && right_lca)
    {
        return root;
    }

    return (left_lca != nullptr) ? left_lca : right_lca;
}
int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->left->left = newNode(4);
    root->right = newNode(3);
    cout << lcautil(root, 4, 3);
    return 0;
}