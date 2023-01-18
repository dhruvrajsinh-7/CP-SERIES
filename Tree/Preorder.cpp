#include <bits/stdc++.h>
using namespace std;\
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> ans;
    helper(root, ans);
    return ans;
}
void helper(TreeNode *root, vector<int> &ans)
{
    if (root != nullptr)
    {
        ans.push_back(root->val);
        helper(root->left, ans);
        helper(root->right, ans);
    }
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    vector<int> ans = preorderTraversal(root);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}