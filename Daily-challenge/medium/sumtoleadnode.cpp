#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
long long res;
void dfshelper(TreeNode *root, long long value)
{
    if (root == NULL)
    {
        return;
    }
    value = value * 10;
    value = value + root->val;
    if (root->left == nullptr && root->right == nullptr)
    {
        res += value;
        return;
    }
    dfshelper(root->left, value);
    dfshelper(root->right, value);
}
int sumNumbers(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    dfshelper(root, 0);
    return res;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    cout << sumNumbers(root);
    return 0;
}