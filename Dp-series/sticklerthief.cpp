#include <bits/stdc++.h>
using namespace std;
int helper(int i, int arr[], vector<int> &dp, int n)
{
    if (i >= n)
    {
        return 0;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }
    return dp[i] = max(helper(i + 1, arr, dp, n), arr[i] + helper(i + 2, arr, dp, n));
}

int FindMaxSum(int arr[], int n)
{
    // Your code here
    vector<int> dp(n + 1, -1);
    return helper(0, arr, dp, n);
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << FindMaxSum(a, n);
    return 0;
}