#include <bits/stdc++.h>
using namespace std;
vector<int> max_of_subarrays(vector<int> arr, int n, int k)
{
    // your code here
    vector<int> ans;
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push({arr[i], i});
    }
    ans.push_back(pq.top().first);
    for (int i = k; i < n; i++)
    {
        pq.push({arr[i], i});
        while ((pq.top().second > i - k) == false)
        {
            pq.pop();
        }
        ans.push_back(pq.top().first);
    }
    return ans;
}
int main()
{
    vector<int> arr = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    vector<int> ans = max_of_subarrays(arr, 9, 3);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}