#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
bool helper(TreeNode *left, TreeNode *right)
{
    if (left == nullptr || right == nullptr)
    {
        if (left == right)
        {
            return true;
        }
        return false;
    }
    if (left->val != right->val)
    {
        return false;
    }
    return helper(left->left, right->right) and helper(left->right, right->left);
}
bool isSymmetric(TreeNode *root)
{
    if (root == nullptr)
    {
        return false;
    }
    return helper(root->left, root->right);
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    cout << isSymmetric(root);
    return 0;
}
