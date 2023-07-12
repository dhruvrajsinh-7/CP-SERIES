#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int val)
    {
        this->val = val;
        left = right = nullptr;
    }
};
void makingGraph(TreeNode *node, TreeNode *parent, unordered_map<int, vector<int>> &graph)
{
    if (node == nullptr)
        return;

    if (parent != nullptr)
    {
        graph[node->val].push_back(parent->val);
        graph[parent->val].push_back(node->val);
    }

    makingGraph(node->left, node, graph);
    makingGraph(node->right, node, graph);
}
vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    unordered_map<int, bool> vis;
    unordered_map<int, vector<int>> graph;
    vector<int> ans;
    queue<int> q;
    int dis = 0;
    makingGraph(root, nullptr, graph);
    q.push(target->val);
    vis[target->val] = true;

    while (!q.empty())
    {
        int size = q.size();
        if (dis == k && !q.empty())
        {
            while (!q.empty())
            {
                ans.push_back(q.front());
                q.pop();
            }
            break;
        }
        for (int i = 0; i < size; i++)
        {
            int node = q.front();
            q.pop();
            for (int it : graph[node])
            {
                if (!vis[it])
                {
                    vis[it] = true;
                    q.push(it);
                }
            }
        }
        dis++;
    }
    return ans;
}
int main()
{
    int n, k;
    cin >> n >> k;
    TreeNode *root = new TreeNode(0);
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        int l, r;
        cin >> l >> r;
        if (l != -1)
        {
            node->left = new TreeNode(l);
            q.push(node->left);
        }
        if (r != -1)
        {
            node->right = new TreeNode(r);
            q.push(node->right);
        }
    }
    int target;
    cin >> target;
    vector<int> ans = distanceK(root, root->left, k);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}