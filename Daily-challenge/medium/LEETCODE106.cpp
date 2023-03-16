#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
map<int, int> mp;
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    int n = inorder.size();
    for (int i = 0; i < n; i++)
    {
        mp[inorder[i]] = i;
    }
    int indexofpost = n - 1;
    return helper(indexofpost, 0, n - 1, inorder, postorder);
}
TreeNode *helper(int &indexofpost, int startofin, int endofin, vector<int> &inorder, vector<int> &postorder)
{
    if (startofin > endofin)
    {
        return nullptr;
    }
    TreeNode *root = new TreeNode(postorder[indexofpost]);
    indexofpost--;
    int indexofin = mp[root->val];
    root->right = helper(indexofpost, indexofin + 1, endofin, inorder, postorder);
    root->left = helper(indexofpost, startofin, indexofin - 1, inorder, postorder);
    return root;
}
int main()
{
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    TreeNode *root = buildTree(inorder, postorder);
    return 0;
}