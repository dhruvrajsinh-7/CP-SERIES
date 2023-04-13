#include <bits/stdc++.h>
using namespace std;
struct root
{
    int data;
    root *left;
    root *right;
    root(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
vector<int> leftView(Node *root)
{
    // Your code here
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 1; i <= size; i++)
        {

            Node *temp = q.front();
            q.pop();

            if (i == 1)
            {
                ans.push_back(temp->data);
            }
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
    return ans;
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
    vector<int> ans = leftView(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}