#include <bits/stdc++.h>
using namespaxce std;
static bool comp(pair<int, int> a, pair<int, int> b)
{
    return (a.second < b.second);
}
int activitySelection(vector<int> start, vector<int> end, int n)
{
    // Your code here
    vector<pair<int, int>> help;
    for (int i = 0; i < n; i++)
    {
        help.push_back(make_pair(start[i], end[i]));
    }
    sort(help.begin(), help.end(), comp);
    int i = 0;
    int count = 1;
    for (int j = 1; j < n; j++)
    {
        if (help[j].first > help[i].second)
        {
            count++;
            i = j;
        }
    }
    return count;
}
int main()
{
    int n;
    cin >> n;
    vector<int> start(n, 0);
    vector<int> end(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> start[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> end[i];
    }
    cout << activitySelection(start, end, n);
    return 0;
}