#include <bits/stdc++.h>
using namespace std;
int maxProduct(vector<int> &nums)
{
    int maxp = 1;
    int minp = 1;
    int res = INT_MIN;
    for (auto it : nums)
    {

        if (it < 0)
        {
            swap(maxp, minp);
        }

        maxp = max(it, it * maxp);
        minp = min(it, it * minp);

        res = max(res, maxp);
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        nums.push_back(x);
    }
    cout << maxProduct(nums);
    return 0;
}