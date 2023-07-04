#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long int helper(vector<vector<long long int>> &dp, int arr[], int n, int i, int j)
{
    if (i > j)
    {
        return dp[i][j] = 0;
    }
    if (i == j)
    {
        return dp[i][j] = arr[i];
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    long long int pick1 = arr[i] + min(helper(dp, arr, n, i + 2, j), helper(dp, arr, n, i + 1, j - 1));
    long long int pick2 = arr[j] + min(helper(dp, arr, n, i, j - 2), helper(dp, arr, n, i + 1, j - 1));

    return dp[i][j] = max(pick1, pick2);
}
long long maximumAmount(int arr[], int n)
{
    vector<vector<long long int>> dp(n + 1, vector<int>(n + 1, -1));
    return helper(dp, arr, n, 0, n - 1);
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[n];
    }
    cout << maximumAmount(arr, n) << endl;
    return 0;
}