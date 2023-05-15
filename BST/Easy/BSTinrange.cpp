#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
void helper(Node *root, int l, int h, int &c)
{
    if (root != NULL)
    {
        helper(root->left, l, h, c);
        if (root->data >= l && root->data <= h)
            c++;
        helper(root->right, l, h, c);
    }
}
int getCount(Node *root, int l, int h)
{
    // your code goes here
    int c;
    helper(root, l, h, c);
    return c;
}
int main() // driver code might be wrong
{
    int t
            cin >>
        t;
    while (t--)
    {
        string s;
        cin >> s;
        int l, h;
        cin >> l >> h;
        Node *root = buildTree(s);
        cout << getCount(root, l, h) << endl;
    }
    return 0;
}