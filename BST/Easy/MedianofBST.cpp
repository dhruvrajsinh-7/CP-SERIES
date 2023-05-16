#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};
void inorder(Node *root, vector<int> &ans)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
    return;
}
float findMedian(struct Node *root)
{
    // Code here
    vector<int> ans;
    inorder(root, ans);
    int n = ans.size();
    if (n % 2 == 0)
    {
        return (ans[n / 2 - 1] + ans[n / 2]) / 2.0f;
    }
    return ans[n / 2];
}
int main()
{
    // Write driver code here
    int n;
    cin >> n;
    Node *root = nullptr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        Node *temp = new Node();
        temp->data = x;
        temp->left = nullptr;
        temp->right = nullptr;
        if (root == nullptr)
        {
            root = temp;
        }
        else
        {
            Node *dummy = root;
            while (true)
            {
                if (x < dummy->data)
                {
                    if (dummy->left == nullptr)
                    {
                        dummy->left = temp;
                        break;
                    }
                    dummy = dummy->left;
                }
                else
                {
                    if (dummy->right == nullptr)
                    {
                        dummy->right = temp;
                        break;
                    }
                    dummy = dummy->right;
                }
            }
        }
    }
    cout << findMedian(root);
    return 0;
}