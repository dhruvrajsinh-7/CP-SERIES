#include <bits/stdc++.h>
using namespace std;

int diagonalSum(vector<vector<int>> &mat)
{
    if (mat.size() == 1)
    {
        return mat[0][0];
    }
    int sum1 = 0;
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            if (i == j || i + j == mat.size() - 1)
            {
                sum1 += mat[i][j];
            }
        }
    }
    return sum1;
}
int main()
{
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << diagonalSum(mat) << endl;
    return 0;
}