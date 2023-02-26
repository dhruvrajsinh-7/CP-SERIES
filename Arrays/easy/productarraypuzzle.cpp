#include <bits/stdc++.h>
using namespace std;
vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
{
    vector<long long int> ans(n, 1);
    long long int prod = 1;
    // code here
    for (int i = 0; i < n; i++)
    {
        ans[i] = ans[i] * prod;
        prod = prod * nums[i];
    }
    prod = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        ans[i] *= prod;
        prod *= nums[i];
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<long long int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<long long int> ans = productExceptSelf(nums, n);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}