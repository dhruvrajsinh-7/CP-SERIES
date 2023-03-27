#include <bits/stdc++.h>
using namespace std;
int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int start = 0, total = 0, tank = 0;
    for (int i = 0; i < gas.size(); i++)
    {
        tank = tank + gas[i] - cost[i];
        if (tank < 0)
        {
            start = i + 1;
            total += tank;
            tank = 0;
        }
    }
    if (total + tank >= 0)
        return start;
    return -1;
}
int main()
{
    int n;
    cin >> n;
    vector<int> gas(n, 0);
    vector<int> cost(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> gas[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }
    cout << canCompleteCircuit(gas, cost);
    return 0;
}