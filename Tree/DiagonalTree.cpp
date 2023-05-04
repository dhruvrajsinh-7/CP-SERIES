#include <bits/stdc++.h>
using namespace std;
vector<int> diagonal(Node *root)
{
    // your code here
    vector<int> ans;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        while (node)
        {
            ans.push_back(node->data);
            q.push(node->left);
            node = node->right;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    Node *root = buildTree(v);
    vector<int> ans = diagonal(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}