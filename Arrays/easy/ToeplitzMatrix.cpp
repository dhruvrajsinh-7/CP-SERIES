#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>> matrix;
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
        matrix.push_back(row);
    }
    bool ans = isToeplitzMatrix(matrix);
    cout << ans << endl;
    return 0;
}
bool isToeplitzMatrix(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    for (int i = 0; i < m - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (matrix[i][j] != matrix[i + 1][j + 1])
            {
                return false;
            }
        }
    }
    return true;
}