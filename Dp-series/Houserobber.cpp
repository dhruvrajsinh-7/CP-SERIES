#include<bits/stdc++.h>
using namespace std;
int rob(vector<int> &nums)
{
    if (nums.size() == 0)
    {
        return 0;
    }
    else if (nums.size() == 1)
    {
        return nums[0];
    }
    else if (nums.size() == 2)
    {
        return max(nums[0], nums[1]);
    }
    else
    {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = nums[0] + nums[2];
        int s = max(dp[2], dp[1]);
        for (int i = 3; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 2], dp[i - 3]) + nums[i];
            s = max(dp[i], s);
        }
        return s;
    }
}
int main(){
    int n;
    cin>>n;
    int x;
    vector<int>nums;
    for(int i=0;i<n;i++){
        cin>>x;
        nums.push_back(x);
    }
    cout<<rob(nums)<<endl;
    return 0;
}