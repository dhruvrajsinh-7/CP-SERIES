#include <bits/stdc++.h>
using namespace std;
int helper(int i, vector<int> &nums, vector<int> &dp)
{
    if (i == 0)
        return nums[i];
    if (i < 0)
        return 0;

    if (dp[i] != -1)
        return dp[i];

    int take = nums[i] + helper(i - 2, nums, dp);
    int nottake = 0 + helper(i - 1, nums, dp);

    return dp[i] = max(take, nottake);
}
int rob(vector<int> &nums)
{
    int n = nums.size();
    vector<int> start;
    vector<int> end;
    if (n == 1)
        return nums[0];
    for (int i = 0; i < n - 1; i++)
    {
        start.push_back(nums[i]);
    }
    for (int i = 1; i < n; i++)
    {
        end.push_back(nums[i]);
    }
    vector<int> dp1(start.size(), -1), dp2(end.size(), -1);
    int ans1 = helper(start.size() - 1, start, dp1);
    int ans2 = helper(end.size() - 1, end, dp2);
    return max(ans1, ans2);
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto &it : nums)
        cin >> it;
    cout << rob(nums) << endl;
    return 0;
}