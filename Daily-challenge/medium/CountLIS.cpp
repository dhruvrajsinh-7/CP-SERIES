#include <bits/stdc++.h>
using namespace std;
int findNumberOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<pair<int, int>>> dp(n + 1, vector<pair<int, int>>(n, {-1, -1}));
    return helper(0, -1, nums, dp, n).second;
}
pair<int, int> helper(int ind, int prev_ind, vector<int> &nums, vector<vector<pair<int, int>>> &dp, int n)
{
    pair<int, int> take = {0, 0};
    pair<int, int> nottake = {0, 0};
    if (ind >= n)
    {
        return {0, 1};
    }
    if (dp[prev_ind + 1][ind].first != -1)
    {
        return dp[ind][prev_ind + 1];
    }
    if (prev_ind == -1 || nums[ind] > nums[prev_ind])
    {
        take = helper(ind + 1, ind, nums, dp, n);
        take.first++;
    }
    nottake = helper(ind + 1, prev_ind, nums, dp, n);
    if (take.first == nottake.first)
    {
        dp[prev_ind + 1][ind] = {take.first, take.second + nottake.second};
    }
    else if (take.first > nottake.first)
    {
        dp[prev_ind + 1][ind] = take;
    }
    else
    {
        dp[prev_ind + 1][ind] = nottake;
    }
    return dp[prev_ind + 1][ind];
}
int main()
{
    vector<int> nums = {1, 3, 5, 4, 7};
    cout << findNumberOfLIS(nums);
    return 0;
}