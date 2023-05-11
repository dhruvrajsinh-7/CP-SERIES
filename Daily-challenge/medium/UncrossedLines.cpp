#include <bits/stdc++.h>
using namespace std;
int maxUncrossedLines(vector<int> &s1, vector<int> &s2)
{
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(0 + dp[i - 1][j], 0 + dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}
int main()
{
    vector<int> s1 = {1, 4, 2};
    vector<int> s2 = {1, 2, 4};
    cout << maxUncrossedLines(s1, s2);
    return 0;
}