#include <bits/stdc++.h>
using namespace std;
struct TrieNode
{
    struct TrieNode *children[26];
    bool isLeaf;
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isLeaf = false;
    }
};
void insert(struct TrieNode *root, string key)
{
    // code here
    int n = key.size();
    for (int i = 0; i < n; i++)
    {
        if (!root->children[key[i] - 'a'])
        {
            root->children[key[i] - 'a'] = new TrieNode();
        }
        root = root->children[key[i] - 'a'];
    }
    root->isLeaf = true;
}

bool search(struct TrieNode *root, string key)
{
    // code here
    int n = key.size();
    for (int i = 0; i < n; i++)
    {
        if (!root->children[key[i] - 'a'])
        {
            return false;
        }
        root = root->children[key[i] - 'a'];
    }
    return root->isLeaf;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        struct TrieNode *root = new TrieNode();
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            insert(root, s);
        }
        string s;
        cin >> s;
        cout << search(root, s) << endl;
    }
    return 0;
}