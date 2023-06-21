#include <bits/stdc++.h>
using namespace std;
vector<int> getAverages(vector<int> &nums, int k)
{
    vector<int> ans(nums.size(), -1);
    long long sum = 0;
    if (k == 0)
    {
        return nums;
    }
    if (nums.size() < 2 * k + 1)
    {
        return ans;
    }
    for (int i = 0; i < 2 * k + 1; i++)
    {
        sum += nums[i];
    }
    ans[k] = sum / (2 * k + 1);
    for (int i = k + 1; i < nums.size() - k; i++)
    {
        sum += nums[k + i];
        sum -= nums[i - k - 1];
        ans[i] = sum / (2 * k + 1);
    }
    return ans;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (auto &it : nums)
        cin >> it;
    vector<int> ans = getAverages(nums, k);
    for (auto it : ans)
        cout << it << " ";
    cout << endl;
    return 0;
}