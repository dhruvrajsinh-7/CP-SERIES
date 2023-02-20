#include <bits/stdc++.h>
using namespace std;
void setZeroes(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int iszerocol = 1;
    int m = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][0] == 0)
        {
            iszerocol = 0;
        }
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 1; j--)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
        if (iszerocol == 0)
        {
            matrix[i][0] = 0;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> matrix;
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
    setZeroes(matrix);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}