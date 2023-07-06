#include <bits/stdc++.h>
using namespace std;
int helper(int idx, int buy, vector<int> &price, int cap, vector<vector<vector<int>>> &dp, int n)
{
    if (cap == 0)
    {
        return 0;
    }
    if (idx == n)
    {
        return 0;
    }
    int profit = 0;
    if (dp[idx][buy][cap] != -1)
    {
        return dp[idx][buy][cap];
    }
    if (buy == 0)
    {
        dp[idx][buy][cap] = max(-price[idx] + helper(idx + 1, 1, price, cap, dp, n), helper(idx + 1, 0, price, cap, dp, n));
    }
    else
    {
        dp[idx][buy][cap] = max(price[idx] + helper(idx + 1, 0, price, cap - 1, dp, n), helper(idx + 1, 1, price, cap, dp, n));
    }
    profit = dp[idx][buy][cap];
    return profit;
}
int maxProfit(int k, vector<int> &price)
{
    int n = price.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
    return helper(0, 0, price, k, dp, n);
}
int main()
{
    vector<int> price = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(2, price);
    return 0;
}