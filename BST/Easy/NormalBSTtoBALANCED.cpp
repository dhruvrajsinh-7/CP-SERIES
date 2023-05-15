#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
void sortedbst(vector<Node *> &nodes, Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    sortedbst(nodes, root->left);
    nodes.push_back(root);
    sortedbst(nodes, root->right);
}
Node *constructtree(int s, int e, vector<Node *> &nodes)
{
    if (s > e)
    {
        return NULL;
    }

    int mid = (s + e) / 2;
    Node *root = nodes[mid];

    root->left = constructtree(s, mid - 1, nodes);
    root->right = constructtree(mid + 1, e, nodes);
    return root;
}
Node *buildBalancedTree(Node *root)
{
    // Code here
    vector<Node *> nodes;
    sortedbst(nodes, root);
    int n = nodes.size() - 1;
    return constructtree(0, n, nodes);
}
int main() // driver code might be wrong
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Node *root = NULL;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            root = insert(root, x);
        }
        root = buildBalancedTree(root);
        inorder(root);
        cout << endl;
    }
    return 0;
}