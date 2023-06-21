#include <bits/stdc++.h>
using namespace std;
int f(int i, int j, int arr[], int N, vector<vector<int>> &dp)
{
    int take = 0, nottake = 0;
    if (j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (i == N || abs(arr[i] - arr[j]) == 1)
        take = 1 + f(j, j - 1, arr, N, dp);
    nottake = f(i, j - 1, arr, N, dp);
    return dp[i][j] = max(take, nottake);
}
int longestSubsequence(int N, int A[])
{
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));
    return f(N, N - 1, A, N, dp);
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (auto &it : arr)
        cin >> it;
    cout << longestSubsequence(n, arr) << endl;
    return 0;
}