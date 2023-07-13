#include <bits/stdc++.h>
using namespace std;
vector<int> singleNumber(vector<int> nums)
{
    // Code here.
    int n = nums.size();
    vector<int> ans;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 1; ++i)
    {
        if ((nums[i] ^ nums[i + 1]) != 0)
            ans.push_back(nums[i]);
        else
        {
            i += 1;
        }
    }

    if (nums[n - 1] != nums[n - 2])
        ans.push_back(nums[n - 1]);

    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    vector<int> ans = singleNumber(nums);
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}