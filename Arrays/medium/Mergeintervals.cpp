#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>> intervals;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        vector<int> row;
        for (int j = 0; j < 2; j++)
        {
            int x;
            cin >> x;
            row.push_back(x);
        }
        intervals.push_back(row);
    }
    vector<vector<int>> ans = merge(intervals);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    merge(intervals);
}
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;
    for (int i = 0; i < n; i++)
    {
        if (merged.empty() || merged.back()[1] < intervals[i][0])
        {
            vector<int> v{
                intervals[i][0],
                intervals[i][1]};
            merged.push_back(v);
        }
        else
        {
            merged.back()[1] = max(merged.back()[1], intervals[i][1]);
        }
    }
    return merged;
}