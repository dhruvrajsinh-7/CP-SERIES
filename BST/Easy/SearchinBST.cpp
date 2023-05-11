#include <bitd/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *searchBST(TreeNode *root, int val)
{
    if (root == NULL || root->val == val)
        return root;
    if (root->val < val)
        return searchBST(root->right, val);
    return searchBST(root->left, val);
}
int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    cout << searchBST(root, 2) << endl;
    return 0;
}