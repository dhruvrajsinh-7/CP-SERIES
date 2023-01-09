#include <iostream>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
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
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    vector<int> ans = preorderTraversal(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}