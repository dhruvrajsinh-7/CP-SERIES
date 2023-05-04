#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> mp;
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

string helper(Node *root)
{
    if (!root)
    {
        return "*";
    }
    string s = "";
    if (root->left == NULL && root->right == NULL)
    {
        s = to_string(root->data);
        return s;
    }
    s += to_string(root->data);
    s += "_";
    s += helper(root->left);
    s += helper(root->right);
    mp[s]++;
    return s;
}
int dupSub(Node *root)
{
    // code here
    helper(root);
    for (auto it : mp)
    {
        if (it.second >= 2)
        {
            return 1;
        }
    }
    return 0;
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
    cout << dupSub(root);
    return 0;
}