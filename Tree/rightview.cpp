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
vector<int> rightSideView(TreeNode *root)
{
    vector<int> res;
    queue<TreeNode *> q;
    if (root == NULL)
    {
        return res;
    }
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 1; i <= size; i++)
        {
            TreeNode *dummy = q.front();
            q.pop();

            if (i == 1)
            {
                res.push_back(dummy->val);
            }
            if (dummy->right)
            {
                q.push(dummy->right);
            }
            if (dummy->left)
            {
                q.push(dummy->left);
            }
        }
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    root *root = new root(n);
    root->left = new root(2);
    root->right = new root(3);
    root->left->left = new root(4);
    root->left->right = new root(5);
    root->right->left = new root(6);
    root->right->right = new root(7);
    vector<int> ans = rightSideView(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}