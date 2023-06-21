#include <bits/stdc++.h>
using namespace std;
int combinationSum4(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<int> dp(target + 1, -1);
    return helper(nums, target, dp);
}
int helper(vector<int> &nums, int target, vector<int> &dp)
{
    if (target == 0)
    {
        return 1;
    }
    if (target < 0)
    {
        return 0;
    }
    if (dp[target] != -1)
    {
        return dp[target];
    }
    int count = 0;
    for (auto it : nums)
    {
        if (it <= target)
        {
            count += helper(nums, target - it, dp);
        }
    }
    dp[target] = count;
    return dp[target];
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto &it : nums)
        cin >> it;
    int target;
    cin >> target;
    cout << combinationSum4(nums, target) << endl;
    return 0;
}