#include <bits/stdc++.h>
using namespace std;
vector<int> printKClosest(vector<int> arr, int n, int k, int x)
{
    // code here
    vector<int> ans;
    priority_queue<pair<int, int>> pq;
    for (auto it : arr)
    {
        if (abs(it - x) != 0)
        {
            pq.push({abs(it - x), -1 * it});
        }
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    while (!pq.empty())
    {
        ans.push_back(-1 * pq.top().second);
        pq.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> ans = printKClosest(arr, n, k, x);
    for (auto it : ans)
        cout << it << " ";
    return 0;
}