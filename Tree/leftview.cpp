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
