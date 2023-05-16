#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};
Node *findsucc(Node *temp, int k, Node *&succ)
{
    if (temp == NULL)
    {
        return temp = new Node(k);
    }
    if (k < temp->data)
    {
        succ = temp;
        temp->left = findsucc(temp->left, k, succ);
    }
    else
    {
        temp->right = findsucc(temp->right, k, succ);
    }
    return temp;
}
vector<int> findLeastGreater(vector<int> &arr, int n)
{
    Node *temp = NULL;
    for (int i = n - 1; i >= 0; i--)
    {
        Node *succ = NULL;
        temp = findsucc(temp, arr[i], succ);
        if (succ)
        {
            arr[i] = succ->data;
        }
        else
        {
            arr[i] = -1;
        }
    }
    return arr;
}
int main()
{
    // Write driver code here
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &i : arr)
    {
        cin >> i;
    }
    arr = findLeastGreater(arr, n);
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}