#include <bits/stdc++.h>
using namespace std;
int knapSack(int N, int W, int val[], int wt[])
{
    vector<vector<int>> dp(N, vector<int>(W + 1, -1));
    return helper(N - 1, W, val, wt, dp);
}

int helper(int idx, int sum, int val[], int wt[], vector<vector<int>> &dp)
{
    if (idx == 0)
    {
        int ans = sum / wt[0];
        return ans * val[0];
    }
    if (dp[idx][sum] != -1)
    {
        return dp[idx][sum];
    }
    int nottake = helper(idx - 1, sum, val, wt, dp);
    int take = 0;
    if (wt[idx] <= sum)
    {
        take = val[idx] + helper(idx, sum - wt[idx], val, wt, dp);
    }
    return dp[idx][sum] = max(take, nottake);
}
int main()
{
    int N, W;
    cin >> N >> W;
    int val[N], wt[N];
    for (int i = 0; i < N; i++)
    {
        cin >> val[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> wt[i];
    }
    cout << knapSack(N, W, val, wt);
    return 0;
}