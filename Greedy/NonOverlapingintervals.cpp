#include <bits/stdc++.h>
using namespace std;
static bool cmp(const vector<int> &a1, const vector<int> &a2)
{
    return a1[1] < a2[1];
}
int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end(), cmp);
    int n = intervals.size();
    int count = 0, endofinterval = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (intervals[i][0] >= endofinterval)
        {
            endofinterval = intervals[i][1];
            count++;
        }
    }
    return n - count;
}
int main()
{
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout << eraseOverlapIntervals(intervals);
    return 0;
}