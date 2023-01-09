#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>> grid;
    vector<vector<int>> ans;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        vector<int> row;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            row.push_back(x);
        }
        grid.push_back(row);
    }
    for (int i = 0; i < n; i++)
    {
        vector<int> row;
        for (int j = 0; j < n; j++)
        {
            row.push_back(grid[j][i]);
        }
        ans.push_back(row);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
vector<int> findBall(vector<vector<int>> &grid)
{
    int n = grid[0].size();
    vector<int> answer(n, 0);
    for (int i = 0; i < n; i++)
    {
        answer[i] = helper(0, i, grid);
    }
    return answer;
}
int helper(int i, int j, vector<vector<int>> &grid)
{
    if (i == grid.size())
    {
        return j;
    }
    int nextj = j + grid[i][j];
    if (nextj < 0 || nextj > grid[0].size() - 1 || grid[i][j] != grid[i][nextj])
    {
        return -1;
    }
    return helper(i + 1, nextj, grid);
}