#include <bits/stdc++.h>
using namespace std;
int solver(vector<int> &coins, int i, int target, vector<int> &ans)
{
    if (target == 0)
        return 0;
    if (i == 0)
    {
        if (target % coins[i] == 0)
        {
            ans.push_back(coins[i]);
            return target / coins[i];
        }
        else
            return 1e8;
    }

    int nottake = INT_MAX;
    int take = INT_MAX;
    if (coins[i] <= target)
    {
        ans.push_back(coins[i]);
        take = 1 + solver(coins, i, target - coins[i], ans);
    }
    else
        nottake = solver(coins, i - 1, target, ans);

    return min(take, nottake);
}
vector<int> minPartition(int N)
{
    // code here
    vector<int> ans;
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    solver(coins, 9, N, ans);
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> ans = minPartition(n);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    return 0;
}