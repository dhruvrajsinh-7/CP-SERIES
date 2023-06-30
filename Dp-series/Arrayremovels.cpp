#inc c
int removals(vector<int> &arr, int k)
{
    // Code here
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    sort(arr.begin(), arr.end());
    if (n == 1)
        return 0;
    else
        return helper(0, n - 1, arr, k, dp);
}
int helper(int i, int j, vector<int> &arr, int k, vector<vector<int>> &dp)
{
    if (i >= j)
    {
        return 0;
    }
    else if ((arr[j] - arr[i]) <= k)
    {
        return 0;
    }
    else if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    else if ((arr[j] - arr[i]) > k)
    {
        dp[i][j] = 1 + min(helper(i + 1, j, arr, k, dp), helper(i, j - 1, arr, k, dp));
    }
    return dp[i][j];
}