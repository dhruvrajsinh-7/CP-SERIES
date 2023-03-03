#include <bits/stdc++.h>
using namespace std;

int minSwaps(vector<int> &nums)
{
    int n = nums.size();
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({nums[i], i});
    }
    sort(v.begin(), v.end());
    int ans = 0;
    bool vis[n] = {false};
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == true || v[i].second == i)
        {
            continue;
        }
        int cnt = 0;
        int j = i;
        while (vis[j] == false)
        {
            vis[j] = true;
            cnt++;
            j = v[j].second;
        }
        ans = ans + cnt - 1;
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << minSwaps(nums);
    return 0;
}