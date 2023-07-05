#include <bits/stdc++.h>
using namespace std;
int longestSubarray(vector<int> &nums)
{
    int cntzeroes = 0;
    int res = 0;
    int j = 0;
    for (int i = 0; i < nums.size();)
    {
        if (nums[i] == 0)
        {
            cntzeroes++;
        }
        if (cntzeroes > 1)
        {
            while (nums[j++] != 0)
                ;
            cntzeroes--;
        }
        res = max(res, i - j);
        i++;
    }
    return res;
}
int main()
{
    vector<int> nums = {1, 1, 1};
    cout << longestSubarray(nums);
    return 0;
}