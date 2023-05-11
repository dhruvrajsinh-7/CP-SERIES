#include <bits/stdc++.h>
using namespace std;
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == nullptr)
    {
        return NULL;
    }
    int current = root->val;
    if (current < p->val && current < q->val)
    {
        return lowestCommonAncestor(root->right, p, q);
    }
    if (current > p->val && current > q->val)
    {
        return lowestCommonAncestor(root->left, p, q);
    }
    return root;
}
int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    cout << lowestCommonAncestor(root, 2, 3) << endl;
    return 0;
}