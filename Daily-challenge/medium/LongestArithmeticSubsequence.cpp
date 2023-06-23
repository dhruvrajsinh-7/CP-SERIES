#include <bits/stdc++.h>
using namespace std;
int longestArithSeqLength(vector<int> &v)
{
    int mx = 0;
    int n = v.size();
    unordered_map<int, int> dp[n + 1];
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            int diff = v[j] - v[i];
            if (dp[j].count(diff))
            {
                dp[i][diff] = dp[j][diff] + 1;
            }
            else
            {
                dp[i][diff] = 2;
            }
            mx = max(mx, dp[i][diff]);
        }
    }
    return mx;
}
int main()
{
    vector<int> v = {3, 6, 9, 12};
    cout << longestArithSeqLength(v);
    return 0;
}