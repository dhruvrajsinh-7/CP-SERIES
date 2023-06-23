#include <bits/stdc++.h>
using namespace std;
int solve(int ind, int W, int wt[], int val[], vector<vector<int>> &dp)
{
    if (W == 0)
        return 0;

    if (ind == 0)
    {
        if (W >= wt[0])
            return val[0];
        else
            return 0;
    }

    if (dp[ind][W] != -1)
        return dp[ind][W];

    int notTaken = solve(ind - 1, W, wt, val, dp);
    int taken = 0;

    if (W >= wt[ind])
    {
        taken = val[ind] + solve(ind - 1, W - wt[ind], wt, val, dp);
    }
    return dp[ind][W] = max(taken, notTaken);
}
// Function to return max value that can be put in knapsack of capacity W.
int knapSack(int W, int wt[], int val[], int n)
{
    // Your code here
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return solve(n - 1, W, wt, val, dp);
}
int main()
{
    int n = 3;
    int W = 4;
    int val[] = {1, 2, 3};
    int wt[] = {4, 5, 1};
    cout << knapSack(W, wt, val, n);
    return 0;
}