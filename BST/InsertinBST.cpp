#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode *insertIntoBST(TreeNode *root, int val)
{
    if (root == nullptr)
    {
        return new TreeNode(val);
    }
    TreeNode *curr = root;
    while (true)
    {
        if (curr->val <= val)
        {
            if (curr->right != nullptr)
            {
                curr = curr->right;
            }
            else
            {
                curr->right = new TreeNode(val);
                break;
            }
        }
        else
        {
            if (curr->left != nullptr)
            {
                curr = curr->left;
            }
            else
            {
                curr->left = new TreeNode(val);
                break;
            }
        }
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

    cout << insertIntoBST(root, 2) << endl;
    return 0;
}