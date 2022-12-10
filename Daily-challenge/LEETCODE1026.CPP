int maxAncestorDiff(TreeNode *root)
{
    return findMaxDiff(root, root->val, root->val);
}

int findMaxDiff(TreeNode *root, int minVal, int maxVal)
{
    if (root == nullptr)
        return 0;

    minVal = min(minVal, root->val);
    maxVal = max(maxVal, root->val);

    int maxDiff = max(abs(root->val - minVal), abs(root->val - maxVal));

    int leftMaxDiff = findMaxDiff(root->left, minVal, maxVal);
    int rightMaxDiff = findMaxDiff(root->right, minVal, maxVal);

    return max(maxDiff, max(leftMaxDiff, rightMaxDiff));
}