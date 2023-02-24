#include <bits/stdc++.h>
using namespace std;

int minimumAverageDifference(vector<int> &nums)
{
    int ans = -1;
    long long minavg = INT_MAX;
    // pair<long,int>>ans={INT_MAX,0};
    int n = nums.size();
    if (n == 0)
    {
        return 0;
    }
    long long suml = 0, sumr = 0;
    for (auto num : nums)
    {
        sumr += num;
    }

    for (int i = 0; i < n; i++)
    {
        suml += nums[i];
        sumr -= nums[i];
        long long tempdiff = 0;
        if (i < n - 1)
        {
            tempdiff = abs(suml / (i + 1) - sumr / (n - i - 1));
        }
        else
        {
            tempdiff = suml / (i + 1);
        }
        if (tempdiff < minavg)
        {
            minavg = tempdiff;
            ans = i;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    cout << minimumAverageDifference(nums);
    return 0;
}
