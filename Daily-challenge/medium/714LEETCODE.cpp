#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> dp;
int helper(vector<int> &prices, int it, int cnt, int fee)
{
    if (it == n - 1)
    {
        if (cnt == 1)
        {
            return prices[it] - fee;
        }
        else
            return 0;
    }
    if (dp[it][cnt] != -1)
        return dp[it][cnt];
    int take = 0;
    int nottake = helper(prices, it + 1, cnt, fee);
    if (cnt == 0)
    {
        take = helper(prices, it + 1, 1, fee) - prices[it];
    }
    else
    {
        take = helper(prices, it + 1, 0, fee) + prices[it] - fee;
    }
    return dp[it][cnt] = max(take, nottake);
}
int maxProfit(vector<int> &prices, int fee)
{
    n = prices.size();
    dp.resize(n, vector<int>(2, -1));
    return helper(prices, 0, 0, fee);
}
int main()
{
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;
    cout << maxProfit(prices, fee);
    return 0;
}