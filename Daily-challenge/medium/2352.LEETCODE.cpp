#include <bits/stdc++.h>
using namespace std;
int equalPairs(vector<vector<int>> &grid)
{
    map<vector<int>, int> count;
    int row = grid.size(), col = grid[0].size(), ans = 0;
    for (vector<int> row : grid)
    {
        ++count[row];
    }
    for (int i = 0; i < row; i++)
    {
        vector<int> column = {};
        for (int j = 0; j < col; j++)
        {
            column.push_back(grid[j][i]);
        }
        ans += count[column];
    }
    return ans;
}
int main()
{
    vector<vector<int>> grid = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}};
    cout << equalPairs(grid);
    return 0;
}