#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

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
int main()
{
    TreeNode *root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);
    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);
    cout << maxAncestorDiff(root);
    return 0;
}