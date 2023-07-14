#include <bits/stdc++.h>
using namespace std;
int longestSubsequence(vector<int> &nums, int difference)
{
    int n = nums.size();
    int ans = 0;
    unordered_map<int, int> dp;

    for (int i = 0; i < n; i++)
    {
        if (dp.find(nums[i] - difference) != dp.end())
            dp[nums[i]] = dp[nums[i] - difference] + 1;
        else
            dp[nums[i]] = 1;

        ans = max(ans, dp[nums[i]]);
    }
    return ans;
}
int main()
{
    int n, difference;
    cin >> n >> difference;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << longestSubsequence(nums, difference) << endl;
    return 0;
}