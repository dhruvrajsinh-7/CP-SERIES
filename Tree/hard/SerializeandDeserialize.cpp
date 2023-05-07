#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

string serialize(TreeNode *root)
{
    string res = "";
    if (!root)
    {
        return "# ";
    }
    res += to_string(root->val) + " ";
    res += serialize(root->left);
    res += serialize(root->right);
    return res;
}
TreeNode *deserialize(string data)
{
    int pos = 0;
    return buildTree(data, pos);
}
TreeNode *buildTree(string &data, int &pos)
{
    if (pos >= data.size())
    {
        return nullptr;
    }
    if (data[pos] == '#')
    {
        pos += 2;
        return nullptr;
    }
    int val = 0;
    int sign = 1;
    if (data[pos] == '-')
    {
        sign = -1;
        pos++;
    }
    while (data[pos] != ' ')
    {
        val = val * 10 + (data[pos] - '0');
        pos++;
    }
    pos++;
    val *= sign;
    TreeNode *root = new TreeNode(val);
    root->left = buildTree(data, pos);
    root->right = buildTree(data, pos);
    return root;
}
int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    string s = serialize(root);
    cout << s << endl;
    TreeNode *head = deserialize(s);
    cout << head->val << endl;
    return 0;
}