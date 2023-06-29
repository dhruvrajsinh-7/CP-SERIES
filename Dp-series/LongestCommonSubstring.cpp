#include <bits/stdc++.h>
using namespace std;
int ans = INT_MIN;
int longestCommonSubstr(string s1, string s2, int n, int m)
{
    // your code here
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    helper(s1, s2, n - 1, m - 1, dp);
    return ans;
}
int helper(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int take = 0;

    if (s1[i] == s2[j])
    {
        take = 1 + helper(s1, s2, i - 1, j - 1, dp);
    }
    helper(s1, s2, i, j - 1, dp);
    helper(s1, s2, i - 1, j, dp);
    ans = max(take, ans);
    return dp[i][j] = take;
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << longestCommonSubstr(s1, s2, s1.size(), s2.size());
    return 0;
}