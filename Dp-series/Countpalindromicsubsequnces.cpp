#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
long long int countPS(string str)
{
    int n = str.size();
    vector<vector<int>> t(1001, vector<int>(1001, -1));
    return ans(str, 0, n - 1, t);
}
long long int ans(string &x, int m, int n, vector<vector<int>> &t)
{
    if (m > n)
    {
        return 0;
    }
    if (m == n)
    {
        return 1;
    }
    if (t[m][n] != -1)
    {
        return t[m][n];
    }
    if (x[m] == x[n])
    {
        t[m][n] = (1 + ans(x, m + 1, n, t) + ans(x, m, n - 1, t)) % mod;
    }
    else
    {
        t[m][n] = (mod + ans(x, m + 1, n, t) + ans(x, m, n - 1, t) - ans(x, m + 1, n - 1, t)) % mod;
    }
    return t[m][n];
}
int main()
{
    string s = "abcb";
    cout << countPS(s);
    return 0;
}