#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> result;
    if (root == NULL)
    {
        return result;
    }
    bool flag = true;
    queue<TreeNode *> qt;
    qt.push(root);
    while (!qt.empty())
    {
        int size = qt.size();
        vector<int> row(size);
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = qt.front();
            qt.pop();
            int idx = (flag) ? i : size - 1 - i;
            row[idx] = node->val;
            if (node->left)
            {
                qt.push(node->left);
            }
            if (node->right)
            {
                qt.push(node->right);
            }
        }
        result.push_back(row);
        flag = !flag;
    }
    return result;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    vector<vector<int>> res = zigzagLevelOrder(root);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}