#include <bits/stdc++.h>
using namespace std;
vector<int> getConcatenation(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(nums.begin(), nums.end());
    for (auto it : nums)
    {
        ans.push_back(it);
    }
    return ans;
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
    vector<int> ans = getConcatenation(nums);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}