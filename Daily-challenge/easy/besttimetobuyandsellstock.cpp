#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector<int> &prices)
{
    int maxcurrent = 0, maxfar = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        maxcurrent += prices[i] - prices[i - 1];
        maxcurrent = max(maxcurrent, 0);
        maxfar = max(maxcurrent, maxfar);
    }
    return maxfar;
}
int main()
{
    int n;
    cin >> n;
    vector<int> prices;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        prices.push_back(x);
    }
    cout << maxProfit(prices);
    return 0;
}