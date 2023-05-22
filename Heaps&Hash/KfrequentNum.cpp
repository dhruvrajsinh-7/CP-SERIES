
#include <bits/stdc++.h>
using namespace std;
vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> helper;

    for (int num : nums)
    {
        helper[num]++;
    }
    priority_queue<pair<int, int>> pq;
    for (auto it = helper.begin(); it != helper.end(); ++it)
    {
        pq.push({it->second, it->first});
    }
    vector<int> res;
    while (k > 0 && !pq.empty())
    {
        res.push_back(pq.top().second);
        pq.pop();
        k--;
    }
    return res;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    vector<int> ans = topKFrequent(v, k);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}