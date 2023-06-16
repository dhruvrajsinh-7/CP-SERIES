#include <bits/stdc++.h>
using namespace std;
struct Trienode
{
    int freq;
    Trienode *child[26]; // a-z
    Trienode()
    {
        freq = 0;
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
    }
};

Trienode *root = new Trienode();
vector<string> findPrefixes(string arr[], int n)
{
    // code here
    vector<string> ans;
    for (int i = 0; i < n; i++)
        buildtrie(arr[i], root);

    for (int i = 0; i < n; i++)
        ans.push_back(buildprefix(arr[i], root));
    return ans;
}

void buildtrie(string s, Trienode *root)
{
    Trienode *curr = root;
    for (int i = 0; i < s.length(); i++)
    {
        int index = s[i] - 'a'; // 25
        if (curr->child[index] == NULL)
            curr->child[index] = new Trienode();
        curr->child[index]->freq++;
        curr = curr->child[index];
    }
}

string buildprefix(string s, Trienode *root)
{
    Trienode *curr = root;
    string ans = "";
    for (int i = 0; i < s.length(); i++)
    {
        int index = s[i] - 'a';
        if (curr->freq == 1)
            break;
        ans += s[i];
        curr = curr->child[index];
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    string arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<string> ans = findPrefixes(arr, n);
    for (auto x : ans)
        cout << x << " ";
    return 0;
}
