int MOD = 1e9 + 7;
long long totalSum = 0, result = 0;
int Sumr(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    long long sum = Sumr(root->left) + Sumr(root->right) + root->val;
    result = max(result, sum * (totalSum - sum));
    return sum;
}
int maxProduct(TreeNode *root)
{
    totalSum = Sumr(root);
    Sumr(root);
    return result % MOD;
}