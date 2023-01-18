#include <bits/stdc++.h>
using namespace std;
int helper(vector<int> a[], vector<bool> vis, vector<bool> &hasApple, int row)
{
    vis[row] = 1;
    int time = 0;
    for (int it : a[row])
    {
        if (!vis[it])
        {
            time += helper(a, vis, hasApple, it);
        }
    }
    if (row == 0)
    {
        return time;
    }
    if (hasApple[row] || time > 0)
    {
        return time + 2;
    }
    return 0;
}
int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
{
    vector<int> a[n];
    for (auto &x : edges)
    {
        a[x[0]].push_back(x[1]);
        a[x[1]].push_back(x[0]);
    }
    vector<bool> vis(n, 0);
    return helper(a, vis, hasApple, 0);
}
int main()
{
    int n = 7;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 4}, {1, 5}, {2, 3}, {2, 6}};
    vector<bool> hasApple = {false, false, true, false, true, true, false};
    cout << minTime(n, edges, hasApple);
    return 0;
}