#include<bits/stdc++.h>
using namespace std;
bool canJump(vector<int> &nums)
{
    int lastposition = nums.size() - 1;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        if (i + nums[i] >= lastposition)
        {
            lastposition = i;
        }
    }
    return lastposition == 0;
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
    cout << canJump(nums);
    return 0;
}
