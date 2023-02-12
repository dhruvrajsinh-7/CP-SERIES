#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &nums)
{
    int s = 0, e = nums.size() - 1;
    while (s < e)
    {
        if (nums[s] < nums[e])
        {
            return nums[s];
        }
        int mid = (s + e) / 2;
        if (nums[mid] >= nums[s])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
    }
    return nums[s];
}
int main()
{
    vector<int> nums{3, 4, 5, 1, 2};
    cout << findMin(nums);
    return 0;
}