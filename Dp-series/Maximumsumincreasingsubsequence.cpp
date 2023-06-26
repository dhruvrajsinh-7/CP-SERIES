#include <bits/stdc++.h>
using namespace std;
int f(int arr[], int i, int j, int n, vector<vector<int>> &dp)
{
    int take = 0, nottake = 0;
    if (j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (i == n || arr[i] > arr[j])
        take = arr[j] + f(arr, j, j - 1, n, dp);
    nottake = f(arr, i, j - 1, n, dp);
    return dp[i][j] = max(take, nottake);
}
int maxSumIS(int arr[], int n)
{
    // Your code goes here
    vector<vector<int>> dp(1009, vector<int>(1009, -1));
    return f(arr, n, n - 1, n, dp);
}
int main()
{
    int arr[] = {1, 101, 2, 3, 100, 4, 5};
    cout << maxSumIS(arr, 7);
    return 0;
}