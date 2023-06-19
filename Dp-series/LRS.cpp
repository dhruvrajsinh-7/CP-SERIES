#include <bits/stdc++.h>
using namespace std;
int t[1001][1001];

int helper(string &s1, string &s2, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;

    if (t[m][n] != -1)
        return t[m][n];

    if (s1[m - 1] == s2[n - 1] && m != n)
    {
        return t[m][n] = 1 + helper(s1, s2, m - 1, n - 1);
    }
    else
    {
        return t[m][n] = max(helper(s1, s2, m, n - 1), helper(s1, s2, m - 1, n));
    }
}

int LongestRepeatingSubsequence(string str)
{
    memset(t, -1, sizeof(t));

    int n = str.size();
    return helper(str, str, n, n);
}
int main()
{
    string s;
    cin >> s;
    cout << LongestRepeatingSubsequence(s) << endl;
    return 0;
}