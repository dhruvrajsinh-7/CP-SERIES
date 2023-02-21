#include <bits/stdc++.h>
using namespace std;
void helper(int i, int j, vector<vector<char>> mat, vector<vector<bool>> visi)
{
    if (i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size() || visi[i][j] || mat[i][j] != 'O')
    {
        return;
    }
    visi[i][j] = true;
    helper(i + 1, j, mat, visi);
    helper(i - 1, j, mat, visi);
    helper(i, j - 1, mat, visi);
    helper(i, j + 1, mat, visi);
    return;
}
vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
{
    // code here
    vector<vector<bool>> visi(n, vector<bool>(m, false));
    for (int i = 0; i < m; i++)
    {
        if (mat[0][i] == 'O' && visi[0][i] == false)
        {
            helper(0, i, mat, visi);
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (mat[n - 1][i] == 'O' && visi[n - 1][i] == false)
        {
            helper(n - 1, i, mat, visi);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (mat[i][0] == 'O' && visi[i][0] == false)
        {
            helper(i, 0, mat, visi);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (mat[i][m - 1] == 'O' && visi[i][m - 1] == false)
        {
            helper(i, m - 1, mat, visi);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 'O' && visi[i][j] == false)
            {
                mat[i][j] = 'X';
            }
        }
    }

    return mat;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> mat(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    vector<vector<char>> ans = fill(n, m, mat);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}