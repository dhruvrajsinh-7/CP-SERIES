#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<TreeNode *> ans;
unordered_map<string, int> subtrees;
vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
{
    dfs(root);
    return ans;
}
string dfs(TreeNode *root)
{
    if (root == nullptr)
    {
        return "null";
    }
    string res = to_string(root->val) + "," + dfs(root->left) + "," +
                 dfs(root->right);
    subtrees[res]++;
    if (subtrees[res] == 2)
    {
        ans.push_back(root);
    }
    return res;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(2);
    root->right->left->left = new TreeNode(4);
    root->right->right = new TreeNode(4);
    vector<TreeNode *> ans = findDuplicateSubtrees(root);
    for (auto i : ans)
    {
        cout << i->val << " ";
    }
    return 0;
}