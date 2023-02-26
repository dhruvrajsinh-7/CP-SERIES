#include <bits/stdc++.h>
using namespace std;
int helper(string &S1, string &S2, int i, int j, vector<vector<int>> &dp)
{

    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (S1[i] == S2[j])
        return dp[i][j] = 0 + helper(S1, S2, i - 1, j - 1, dp);

    else
        return dp[i][j] = 1 + min(helper(S1, S2, i - 1, j - 1, dp), min(helper(S1, S2, i - 1, j, dp), helper(S1, S2, i, j - 1, dp)));
}
int minDistance(string &S1, string &S2)
{
    int n = S1.size();
    int m = S2.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));
    return helper(S1, S2, n - 1, m - 1, dp);
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << minDistance(s1, s2);
    return 0;
}