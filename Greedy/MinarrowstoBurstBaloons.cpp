#include <bits/stdc++.h>
using namespace std;
int findMinArrowShots(vector<vector<int>> &points)
{
    sort(points.begin(), points.end());
    int cnt = 1;
    vector<int> prev = points[0];
    int n = points.size();
    for (int i = 0; i < n; i++)
    {
        int curr_sp = points[i][0];
        int curr_ep = points[i][1];

        int prev_sp = prev[0];
        int prev_ep = prev[1];
        if (curr_sp > prev_ep)
        {
            cnt++;
            prev = points[i];
        }
        else
        {
            prev[0] = max(prev_sp, curr_sp);
            prev[1] = min(prev_ep, curr_ep);
        }
    }
    return cnt;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> points(n, vector<int>(2, 0));
    for (int i = 0; i < n; i++)
    {
        cin >> points[i][0];
        cin >> points[i][1];
    }
    cout << findMinArrowShots(points);
    return 0;
}