#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void merge_sort(vector<int> &nums, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int mid = (left + right) / 2;
    merge_sort(nums, left, mid);
    merge_sort(nums, mid + 1, right);
    merge(nums, left, mid, right);
}

vector<int> sortArray(vector<int> &nums)
{
    merge_sort(nums, 0, nums.size() - 1);
    return nums;
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    sortArray(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}