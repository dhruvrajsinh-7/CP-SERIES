#include <bits/stdc++.h>
using namespace std;
int maxIceCream(vector<int> &costs, int coins)
{
    sort(costs.begin(), costs.end());
    int c = -1, sum = 0;
    int i = 0;
    for (auto it : costs)
    {
        if (it <= coins)
        {
            coins -= it;
            c++;
        }
        else
        {
            return i;
        }
        i++;
    }
    return costs.size();
}
int main()
{
    vector<int> costs = {1, 3, 2, 4, 1};
    int coins = 7;
    cout << maxIceCream(costs, coins);
    return 0;
}


