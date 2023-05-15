#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};
TreeNode *bstFromPreorder(vector<int> &preorder)
{
    int i = 0;
    return helper(i, INT_MAX, preorder);
}
TreeNode *helper(int &i, int range, vector<int> &pre)
{
    if (i == pre.size() || pre[i] > range)
    {
        return NULL;
    }
    TreeNode *root = new TreeNode(pre[i++]);
    root->left = helper(i, root->val, pre);
    root->right = helper(i, range, pre);
    return root;
}
int main()
{
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    TreeNode *root = bstFromPreorder(preorder);
    return 0;
}