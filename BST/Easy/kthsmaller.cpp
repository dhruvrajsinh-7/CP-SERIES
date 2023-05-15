#include <bits/stdc++.h>
using namespace std;
void inorder(TreeNode *root, int &k, int &ans)
{
    if (root == NULL)
        return;

    inorder(root->left, k, ans);
    k--;

    if (k == 0)
    {
        ans = root->val;
        return;
    }

    inorder(root->right, k, ans);
}
int kthSmallest(TreeNode *root, int k)
{
    int ans = 0;
    inorder(root, k, ans);
    return ans;
}