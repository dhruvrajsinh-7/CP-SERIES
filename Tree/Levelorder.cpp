#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    queue<TreeNode *> q;
    if (root == NULL)
    {
        return ans;
    }
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> row;
        for (int i = 0; i < size; i++)
        {
            TreeNode *dummy = q.front();
            q.pop();
            if (dummy->left)
            {
                q.push(dummy->left);
            }
            if (dummy->right)
            {
                q.push(dummy->right);
            }
            row.push_back(dummy->val);
        }
        ans.push_back(row);
    }
    return ans;
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
    vector<vector<int>> res = levelOrder(root);
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