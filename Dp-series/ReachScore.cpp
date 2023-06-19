#include <bits/stdc++.h>
using namespace std;
long long helper(int ch, long long n, vector<vector<long long>> &dp, int choice[])
{
    if (n == 0)
    {
        return 1;
    }
    if (ch < 0 || n < 0)
    {
        return 0;
    }
    if (dp[n][ch] != -1)
    {
        return dp[n][ch];
    }
    long long take = helper(ch, n - choice[ch], dp, choice);
    long long nottake = helper(ch - 1, n, dp, choice);
    return dp[n][ch] = take + nottake;
}
long long int count(long long int n)
{
    int choice[3] = {3, 5, 10};
    vector<vector<long long>> dp(n + 1, vector<long long>(3, -1));

    return helper(2, n, dp, choice);
}
int main()
{
    long long int n;
    cin >> n;
    cout << count(n);
    return 0;
}