#include <bits/stdc++.h>
using namespace std;
int majorityElement(vector<int> &nums)
{
    int n = nums.size();
    int ans = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            ans = nums[i];
            count++;
        }
        else
        {
            if (ans == nums[i])
            {
                count++;
            }
            else
            {
                count--;
            }
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
    cout << majorityElement(nums);
    return 0;
}