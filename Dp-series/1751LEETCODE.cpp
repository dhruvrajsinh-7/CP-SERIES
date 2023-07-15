vector<vector<int>> dp;
#include <bits/stdc++.h>
using namespace std;
int maxValue(vector<vector<int>> &events, int k)
{
    int n = events.size();
    dp.resize(n, vector<int>(k + 1, -1));
    sort(events.begin(), events.end(), cmp);
    return helper(0, -1, events, k);
}

static bool cmp(const vector<int> &a, const vector<int> &b)
{
    return a[0] < b[0];
}

int helper(int idx, int prev_idx, vector<vector<int>> &events, int k)
{
    if (idx == events.size() || k == 0)
    {
        return 0;
    }
    if (prev_idx == -1 || events[prev_idx][1] < events[idx][0])
    {
        if (dp[idx][k] != -1)
        {
            return dp[idx][k];
        }
        return dp[idx][k] = max(helper(idx + 1, idx, events, k - 1) + events[idx][2],
                                helper(idx + 1, prev_idx, events, k));
    }
    else
    {
        return helper(idx + 1, prev_idx, events, k);
    }
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> events(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        cin >> events[i][0] >> events[i][1] >> events[i][2];
    }
    cout << maxValue(events, k) << endl;
    return 0;
}