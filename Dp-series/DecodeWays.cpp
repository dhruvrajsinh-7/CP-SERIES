#include <bits/stdc++.h>
using namespace std;
int numDecodings(string s)
{
    int n = s.size();
    vector<int> dp(n + 1, -1);
    int ans = helper(s, 0, n, dp);
    return ans;
}
int helper(string s, int i, int n, vector<int> &dp)
{
    if (s[i] == '0')
        return 0;
    if (i >= n)
        return 1;
    if (dp[i] != -1)
        return dp[i];
    int one = helper(s, i + 1, n, dp);
    int two = 0;
    if (i < n - 1 and (s[i] == '1' or (s[i] == '2' and s[i + 1] <= '6')))
        two = helper(s, i + 2, n, dp);
    return dp[i] = one + two;
}
int main()
{
    string s = "226";
    cout << numDecodings(s);
    return 0;
}