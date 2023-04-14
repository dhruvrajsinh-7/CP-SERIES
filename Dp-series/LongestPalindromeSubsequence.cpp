string reverse(string s1)
{
    string str = "";
    for (int i = s1.length() - 1; i >= 0; i--)
        str += s1[i];
    return str;
}
int helper(int n1, int n2, string s1, string s2)
{
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));

    for (int i = 0; i <= n1; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= n2; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n1][n2];
}
int longestPalindromeSubseq(string a)
{
    int n1 = a.length(), n2 = a.length();
    return helper(n1, n2, a, reverse(a));
}