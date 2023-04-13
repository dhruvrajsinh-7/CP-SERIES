#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};
bool isSubtree(TreeNode *root, TreeNode *subRoot)
{
    if (root == nullptr)
    {
        return false;
    }
    if (subRoot == nullptr)
    {
        return true;
    }
    if (issame(root, subRoot))
    {
        return true;
    }
    return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
}
bool issame(TreeNode *root, TreeNode *subRoot)
{
    if (!root && !subRoot)
    {
        return true;
    }
    if (root && subRoot && root->val == subRoot->val)
    {
        return (
            issame(root->left, subRoot->left) && issame(root->right, subRoot->right));
    }
    return false;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    TreeNode *subRoot = new TreeNode(2);
    subRoot->left = new TreeNode(4);
    subRoot->right = new TreeNode(5);
    cout << isSubtree(root, subRoot);
    return 0;
}