#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int> &nums)
{
    unordered_map<int, int> mp;
    for (auto it : nums)
    {
        mp[it]++;
    }
    for (auto it : mp)
    {
        if (it.second == 1)
        {
            return it.first;
        }
    }
    return 0;
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
    cout << singleNonDuplicate(nums);
    return 0;
}