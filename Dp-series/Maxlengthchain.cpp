#include <bits/stdc++.h>
using namespace std;
int dp[107][107];
int f(int i, int j, struct val p[], int n)
{
    int take = 0, nottake = 0;
    if (j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (i == n || (p[i].first > p[j].second))
        take = 1 + f(j, j - 1, p, n);
    nottake = f(i, j - 1, p, n);
    return dp[i][j] = max(take, nottake);
}
static bool comp(struct val a, struct val b)
{
    return a.second < b.second;
}
int maxChainLen(struct val p[], int n)
{
    // Your code here
    sort(p, p + n, comp);
    memset(dp, -1, sizeof(dp));
    return f(n, n - 1, p, n);
}
int main()
{
    int n;
    cin >> n;
    struct val p[n];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].first >> p[i].second;
    }
    cout << maxChainLen(p, n) << endl;
    return 0;
}