#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};
int maxLevelSum(TreeNode *root)
{
    int maxSum = INT_MIN;
    int maxLevel = 1;
    int level = 1;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int levelSum = 0;
        int levelSize = q.size();

        for (int i = 0; i < levelSize; ++i)
        {
            TreeNode *node = q.front();
            q.pop();

            levelSum += node->val;

            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }

        if (levelSum > maxSum)
        {
            maxSum = levelSum;
            maxLevel = level;
        }

        level++;
    }

    return maxLevel;
}
int main()
{
    int n;
    cin >> n;
    TreeNode *root = new TreeNode(n);
    cout << maxLevelSum(root);
    return 0;
}