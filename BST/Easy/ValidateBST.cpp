#include <bits/stdc++.h>
using namespace std;
bool isValidBST(TreeNode *root)
{
    return checkBST(LONG_MIN, LONG_MAX, root);
}
bool checkBST(long minn, long maxx, TreeNode *root)
{
    if (root == nullptr)
    {
        return true;
    }
    if (root->val >= maxx || root->val <= minn)
    {
        return false;
    }
    return checkBST(minn, root->val, root->left) && checkBST(root->val, maxx, root->right);
}