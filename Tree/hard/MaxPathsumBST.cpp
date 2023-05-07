#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int maxPathSum(TreeNode *root)
{
    int max_sum = INT_MIN;
    helper(root, max_sum);
    return max_sum;
}
int helper(TreeNode *root, int &max_sum)
{
    if (!root)
    {
        return 0;
    }
    int left_sum = max(0, helper(root->left, max_sum));
    int right_sum = max(0, helper(root->right, max_sum));
    max_sum = max(max_sum, root->val + left_sum + right_sum);
    return root->val + max(left_sum, right_sum);
}
int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    cout << maxPathSum(root) << endl;
    return 0;
}