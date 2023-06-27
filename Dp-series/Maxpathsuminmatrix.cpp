#include <bits/stdc++.h>
using namespace std;
int helper(int i, int j, int N, vector<vector<int>> Matrix)
{
    if (j < 0 || j >= N)
        return -1e9;
    if (i == 0)
        return Matrix[0][j];

    int up = Matrix[i][j] + helper(i - 1, j, N, Matrix);
    int ld = Matrix[i][j] + helper(i - 1, j - 1, N, Matrix);
    int rd = Matrix[i][j] + helper(i - 1, j + 1, N, Matrix);

    return max(up, max(ld, rd));
}

int maximumPath(int N, vector<vector<int>> Matrix)
{
    int maxi = INT_MIN;

    for (int j = 0; j < N; j++)
    {
        int ans = helper(N - 1, j, N, Matrix);
        maxi = max(maxi, ans);
    }
    return maxi;
}
int main()
{
    int N;
    cin >> N;
    vector<vector<int>> Matrix(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> Matrix[i][j];

    cout << maximumPath(N, Matrix) << endl;
    return 0;
}