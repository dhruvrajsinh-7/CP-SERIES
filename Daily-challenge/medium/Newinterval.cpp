#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>> intervals;
    vector<int> newInterval;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        int a, b;
        cin >> a >> b;
        temp.push_back(a);
        temp.push_back(b);
        intervals.push_back(temp);
    }
    insert(intervals, newInterval);
    return 0;
}
vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    vector<vector<int>> ans;
    for (auto i : intervals)
    {
        if (i[1] < newInterval[0])
            ans.push_back(i);
        else if (newInterval[1] < i[0])
        {
            ans.push_back(newInterval);
            newInterval = i;
        }
        else
        {
            newInterval[0] = min(newInterval[0], i[0]);
            newInterval[1] = max(newInterval[1], i[1]);
        }
    }
    ans.push_back(newInterval);
    return ans;
}