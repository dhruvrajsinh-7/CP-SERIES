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
void helper(Node *root, int level, set<int> &s)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        s.insert(level);
    }

    helper(root->left, level + 1, s);
    helper(root->right, level + 1, s);
}
/*You are required to complete this method*/
bool check(Node *root)
{
    set<int> s;
    helper(root, 0, s);
    bool ans = false;
    if (s.size() == 1)
    {
        ans = true;
    }
    return ans;
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(8);
    if (check(root))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}