#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s)
{
    int n = s.size();
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    int st = 0;
    int e = 1;
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            dp[i][i + 1] = 1;
            st = i;
            e = 2;
        }
    }
    for (int i = 2; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            int l = j;
            int r = i + j;
            if (dp[l + 1][r - 1] == 1 && s[l] == s[r])
            {
                dp[l][r] = 1;
                st = j;
                e = i + 1;
            }
        }
    }
    return s.substr(st, e);
}
int main()
{
    string s;
    cin >> s;
    cout << longestPalindrome(s);
    return 0;
}