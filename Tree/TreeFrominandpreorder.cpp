#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int n = inorder.size();
    int m = preorder.size();
    for (int i = 0; i < n; i++)
    {
        mp[inorder[i]] = i;
    }
    TreeNode *root = helper(preorder, 0, m - 1, inorder, 0, n - 1);
    return root;
}
TreeNode *helper(vector<int> preorder, int indpreleft, int indpreright, vector<int> inorder, int indinleft, int indinright)
{
    if (indpreleft > indpreright || indinleft > indinright)
    {
        return nullptr;
    }
    TreeNode *root = new TreeNode(preorder[indpreleft]);
    int inroot = mp[root->val];
    int numleft = inroot - indinleft;
    root->left = helper(preorder, indpreleft + 1, indpreleft + numleft, inorder, indinleft, inroot - 1);
    root->right = helper(preorder, indpreleft + numleft + 1, indpreright, inorder, inroot + 1, indinright);
    return root;
}
void print(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->val << " ";
    print(root->left);
    print(root->right);
}
int main()
{
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    TreeNode *root = buildTree(preorder, inorder);
    print(root);
    return 0;
}