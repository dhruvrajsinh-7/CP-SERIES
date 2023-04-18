#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
vector<int> topView(Node *root)
{
    // Your code here
    vector<int> ans;
    if (root == NULL)
        return ans;

    map<int, int> mp;
    queue<pair<Node *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        Node *node = it.first;
        int line = it.second;

        if (mp.find(line) == mp.end())
            mp[line] = node->data;
        if (node->left != NULL)
            q.push({node->left, line - 1});
        if (node->right != NULL)
            q.push({node->right, line + 1});
    }
    for (auto i : mp)
        ans.push_back(i.second);

    return ans;
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);
    vector<int> ans = topView(root);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}