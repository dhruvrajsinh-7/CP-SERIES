#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return (temp);
}
void leftBoundary(Node *root, vector<int> &ans)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }
    ans.push_back(root->data);
    cout << "this is left side" << endl;
    cout << root->data << endl;
    if (root->left != NULL)
        leftBoundary(root->left, ans);

    else
        leftBoundary(root->right, ans);
}
void leafTraversal(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        cout << "this is leaf " << endl;
        cout << root->data << endl;
        return;
    }
    leafTraversal(root->left, ans);
    leafTraversal(root->right, ans);
}
void rightBoundary(Node *root, vector<int> &ans)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }
    if (root->right != NULL)
    {
        rightBoundary(root->right, ans);
        cout << "this is right side" << endl;
        cout << root->data << endl;
    }
    else
        rightBoundary(root->left, ans);
    ans.push_back(root->data);
}
vector<int> boundary(Node *root)
{
    vector<int> ans;
    ans.push_back(root->data);

    leftBoundary(root->left, ans);

    leafTraversal(root->left, ans);
    leafTraversal(root->right, ans);

    rightBoundary(root->right, ans);
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
    Node *root = newNode(v[0]);
    queue<Node *> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < n)
    {
        Node *node = q.front();
        q.pop();
        if (node->left == NULL)
        {
            node->left = newNode(v[i]);
            i++;
            q.push(node->left);
        }
        if (node->right == NULL && i < n)
        {
            node->right = newNode(v[i]);
            i++;
            q.push(node->right);
        }
    }
    vector<int> ans = boundary(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}