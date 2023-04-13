#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
vector<int> reverseLevelOrder(Node *root)
{
    // code here
    vector<int> ans;
    queue<Node *> q;
    if (root == nullptr)
    {
        return ans;
    }
    q.push(root);
    while (!q.empty())
    {
        Node *dummy = q.front();
        q.pop();

        ans.push_back(dummy->data);
        if (dummy->right)
        {
            q.push(dummy->right);
        }
        if (dummy->left)
        {
            q.push(dummy->left);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    int n;
    cin >> n;
    Node *root = new Node(n);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<int> res = reverseLevelOrder(root);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}