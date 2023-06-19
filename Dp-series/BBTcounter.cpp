#include <bits/stdc++.h>
using namespace std;
long long int countBT(int h)
{
    // code here
    if (h == 0 or h == 1)
    {
        return 1;
    }

    long long int MOD = 1000000007;

    long long int dp[h + 1];
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= h; i++)
    {
        dp[i] = (dp[i - 1] * ((2 * dp[i - 2]) % MOD + dp[i - 1])) % MOD;
    }

    return dp[h];
}
int main()
{
    int h;
    cin >> h;
    cout << countBT(h);
    return 0;
}