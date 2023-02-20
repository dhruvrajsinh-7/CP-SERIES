#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> nums;
    int target;
    cin >> target;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    int ans = searchInsert(nums, target);
    return ans;
}
int searchInsert(vector<int> &nums, int target)
{
    int high = nums.size() - 1, low = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (target == nums[mid])
        {
            return mid;
        }
        else if (target > nums[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}