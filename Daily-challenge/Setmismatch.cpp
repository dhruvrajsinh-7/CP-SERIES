#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    findErrorNums(nums);
    return 0;
}
vector<int> findErrorNums(vector<int> &nums)
{
    unordered_map<int, int> map;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        map[nums[i]]++;
    }
    for (auto &ele : map)
    {
        if (ele.second == 2)
        {
            ans.push_back(ele.first);
        }
    }
    for (int i = 1; i <= nums.size(); i++)
    {
        if (map[i] == 0)
        {
            ans.push_back(i);
        }
    }
    return ans;
}