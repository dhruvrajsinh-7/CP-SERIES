#include <bits/stdc++.h>
using namespace std;
vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
{
    sort(nums.begin(), nums.end());
    int sum = 0;
    vector<int> sum1;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        sum1.push_back(sum);
    }

    vector<int> ans(queries.size(), 0);
    for (int i = 0; i < queries.size(); i++)
    {
        for (int j = 0; j < nums.size(); j++)
        {
            if (sum1[j] <= queries[i])
                ans[i] = j + 1;
            else
                break;
        }
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
    int q;
    cin >> q;
    vector<int> queries(q);
    for (int i = 0; i < q; i++)
    {
        cin >> queries[i];
    }
    vector<int> ans = answerQueries(nums, queries);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
