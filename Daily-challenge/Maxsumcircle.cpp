#include <bits/stdc++.h>
using namespace std;
int maxSubarraySumCircular(vector<int> &nums)
{
    int max_sum = INT_MIN, min_sum = INT_MAX;
    int curr_max = 0, curr_min = 0, total = 0;
    for (auto it : nums)
    {
        curr_max = max(it, it + curr_max);
        max_sum = max(curr_max, max_sum);
        total += it;
    }
    for (auto it : nums)
    {
        curr_min = min(it, it + curr_min);
        min_sum = min(curr_min, min_sum);
    }
    if (max_sum > 0)
    {
        if (total - min_sum > max_sum)
        {
            max_sum = total - min_sum;
            return max_sum;
        }
    }
    return max_sum;
}
int main()
{
    vector<int> nums = {1, -2, 3, -2};
    cout << maxSubarraySumCircular(nums);
    return 0;
}