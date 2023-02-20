#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> nums{1, 2, 3, 1, 1, 3};
    return removeDuplicates(nums);
}
int removeDuplicates(vector<int> &nums)
{
    int point = 1;
    int n = nums.size();
    if (n == 0)
    {
        return 0;
    }
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i - 1] != nums[i])
        {
            nums[point] = nums[i];
            point++;
        }
    }
    return point;
}