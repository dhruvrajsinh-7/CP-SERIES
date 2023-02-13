#include <bits/stdc++.h>
using namespace std;
int partion(vector<int> &nums, int left, int right)
{
    int pivot = nums[left], l = left + 1, r = right;
    while (l <= r)
    {
        if (nums[l] < pivot && nums[r] > pivot)
        {
            swap(nums[l++], nums[r--]);
        }
        if (nums[l] >= pivot)
        {
            l++;
        }
        if (nums[r] <= pivot)
        {
            r--;
        }
    }
    swap(nums[left], nums[r]);
    return r;
}
int findKthLargest(vector<int> &nums, int k)
{
    int left = 0, right = nums.size() - 1, k1;
    while (true)
    {
        int idx = partion(nums, left, right);
        if (idx == k - 1)
        {
            k1 = nums[idx];
            break;
        }
        if (idx < k - 1)
        {
            left = idx + 1;
        }
        else
        {
            right = idx - 1;
        }
    }
    return k1;
}
int main()
{
    int n;
    cin >> n;
    int x;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        nums.push_back(x);
    }
    int k;
    cin >> k;
    cout << findKthLargest(nums, k);
    return 0;
}