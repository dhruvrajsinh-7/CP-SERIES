#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *Link[2];
    int end = 0;
};

void solve(int row, int col, int M[MAX][MAX], Node *root, vector<vector<int>> &ans)
{
    vector<int> temp;
    for (int i = 0; i < col; i++)
    {
        int ele = M[row][i];
        temp.push_back(ele);
        if (!root->Link[ele])
        {
            root->Link[ele] = new Node();
        }
        root = root->Link[ele];
    }
    root->end++;
    if (root->end == 1)
    {
        ans.push_back(temp);
    }
}

vector<vector<int>> uniqueRow(int M[MAX][MAX], int row, int col)
{
    vector<vector<int>> ans;

    // Insertion in TRIE
    Node *root = new Node();
    for (int i = 0; i < row; i++)
    {
        solve(i, col, M, root, ans);
    }
    return ans;
}
int main()
{
    int row, col;
    cin >> row >> col;
    int M[MAX][MAX];
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> M[i][j];
    vector<vector<int>> ans = uniqueRow(M, row, col);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < col; j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}