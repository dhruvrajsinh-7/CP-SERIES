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