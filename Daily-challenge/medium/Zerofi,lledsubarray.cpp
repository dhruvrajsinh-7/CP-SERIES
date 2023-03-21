#include <bits/stdc++.h>
using namespace std;
long long zeroFilledSubarray(vector<int> &nums)
{
    long long count = 0, len = 0;
    for (auto it : nums)
    {
        if (it == 0)
        {
            len++;
            count += len;
        }
        else
        {
            len = 0;
        }
    }
    return count;
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
    cout << zeroFilledSubarray(nums);
    return 0;
}