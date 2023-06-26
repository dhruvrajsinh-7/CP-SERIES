#include <bits/stdc++.h>
using namespace std;
long long totalCost(vector<int> &costs, int k, int candidates)
{
    priority_queue<int, vector<int>, greater<int>> p1;
    priority_queue<int, vector<int>, greater<int>> p2;
    long long ans = 0;
    int left = 0, right = costs.size() - 1;
    int c = 0;
    while (c < k)
    {
        for (; p1.size() < candidates && left <= right; left++)
        {
            p1.push(costs[left]);
        }
        for (; p2.size() < candidates && right >= left; right--)
        {
            p2.push(costs[right]);
        }
        int top1 = p1.size() > 0 ? p1.top() : 1e5 + 7;
        int top2 = p2.size() > 0 ? p2.top() : 1e5 + 7;

        if (top1 <= top2)
        {
            ans += top1;
            p1.pop();
        }
        else
        {
            ans += top2;
            p2.pop();
        }
        c++;
    }
    return ans;
}
int main()
{
    int n, k, c;
    cin >> n >> k >> c;
    vector<int> costs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> costs[i];
    }
    cout << totalCost(costs, k, c);
    return 0;
}