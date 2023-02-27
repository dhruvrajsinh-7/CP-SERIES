#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node()
    {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
Node *dfs(vector<vector<int>> grid, int n, int row, int col)
{
    bool allsame = true;
    for (int i = 0; i < n && allsame; i++)
    {
        for (int j = 0; j < n && allsame; j++)
        {
            if (grid[row][col] != grid[row + i][col + j])
            {
                allsame = false;
            }
        }
    }
    Node *ans;
    if (allsame)
    {
        return new Node(grid[row][col], true);
    }

    n = n / 2;
    Node *root = new Node();
    root->topLeft = dfs(grid, n, row, col);
    root->topRight = dfs(grid, n, row, col + n);
    root->bottomLeft = dfs(grid, n, row + n, col);
    root->bottomRight = dfs(grid, n, row + n, col + n);
    return root;
}
Node *construct(vector<vector<int>> &grid)
{
    int n = grid.size();
    return dfs(grid, n, 0, 0);
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    Node *root = construct(grid);
    return 0;
}