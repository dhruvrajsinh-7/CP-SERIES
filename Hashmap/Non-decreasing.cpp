#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> findSubsequences(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> ans;
    vector<vector<vector<int>>> res(n);

    for (int i = 0; i != n; i++)
    {
        for (int j = i + 1; j != n; j++)
            if (nums[i] <= nums[j])
            {
                res[j].push_back({nums[i]});
                for (int k = 0; k < res[i].size(); k++)
                {
                    res[j].push_back(res[i][k]);
                    res[j].back().push_back(nums[i]);
                }
            }
        for (int k = 0; k < res[i].size(); k++)
        {
            ans.push_back(res[i][k]);
            ans.back().push_back(nums[i]);
        }
    }

    sort(ans.begin(), ans.end());
    ans.resize(distance(ans.begin(), unique(ans.begin(), ans.end())));
    return ans;
}
int main(){
    vector<int> nums = {4,6,7,7};
    vector<vector<int>> ans = findSubsequences(nums);
    for(auto i: ans){
        for(auto j: i)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}