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
string collectSubtrees(Node *root, unordered_map<string, int> &subtrees, vector<Node *> &duplicates)
{
    if (!root)
    {
        return "";
    }
    string subtree = to_string(root->data) + "," + collectSubtrees(root->left, subtrees, duplicates) + "," + collectSubtrees(root->right, subtrees, duplicates);
    if (subtrees.count(subtree))
    {
        subtrees[subtree]++;
        if (subtrees[subtree] == 2)
        {
            duplicates.push_back(root);
        }
    }
    else
    {
        subtrees[subtree] = 1;
    }
    return subtree;
}

vector<Node *> printAllDups(Node *root)
{
    // Code here
    vector<Node *> duplicates;
    unordered_map<string, int> subtrees;
    collectSubtrees(root, subtrees, duplicates);
    return duplicates;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        Min distance between two given nodes of a Binary Tree

        {
            string s;
            getline(cin, s);
            Node *root = buildTree(s);
            vector<Node *> res = printAllDups(root);
            if (res.size() == 0)
                cout << "-1";
            else
            {
                for (int i = 0; i < res.size(); i++)
                {
                    cout << res[i]->data << " ";
                }
            }
            cout << endl;
        }
    return 0;
}