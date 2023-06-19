#include <bits/stdc++.h>
using namespace std;
int maxSubstring(string S)
{
    int n = S.length();
    vector<int> dp(n + 1, 0);
    int count0 = 0, count1 = 0;
    int maxDiff = 0;

    for (int i = 1; i <= n; i++)
    {
        if (S[i - 1] == '0')
        {
            count0++;
        }
        else
        {
            count1++;
        }

        dp[i] = count0 - count1;

        for (int j = i - 2; j >= 0; j--)
        {
            if (dp[j] > dp[i])
            {
                dp[i] = dp[j];
            }
        }

        maxDiff = max(maxDiff, dp[i]);
    }

    return maxDiff;
}
int main()
{
    string s;
    cin >> s;
    cout << maxSubstring(s);
    return 0;
}