#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
bool leafSimilar(TreeNode *root1, TreeNode *root2)
{
    vector<int> ans1;
    vector<int> ans2;
    dfs(root1, ans1);
    dfs(root2, ans2);
    if (ans1 == ans2)
        return true;
    return false;
}
void dfs(TreeNode *node, vector<int> &ans)
{
    if (node == NULL)
    {
        return;
    }
    if (node->left == NULL && node->right == NULL)
        ans.push_back(node->val);
    dfs(node->left, ans);
    dfs(node->right, ans);
}
int main()
{
    TreeNode *root1 = new TreeNode(3);
    root1->left = new TreeNode(5);
    root1->right = new TreeNode(1);
    root1->left->left = new TreeNode(6);
    root1->left->right = new TreeNode(2);
    root1->left->right->left = new TreeNode(7);
    root1->left->right->right = new TreeNode(4);
    root1->right->left = new TreeNode(9);
    root1->right->right = new TreeNode(8);
    TreeNode *root2 = new TreeNode(3);
    root2->left = new TreeNode(5);
    root2->right = new TreeNode(1);
    root2->left->left = new TreeNode(6);
    root2->left->right = new TreeNode(7);
    root2->right->left = new TreeNode(4);
    root2->right->right = new TreeNode(2);
    root2->right->right->left = new TreeNode(9);
    root2->right->right->right = new TreeNode(8);
    cout << leafSimilar(root1, root2);
    return 0;
}