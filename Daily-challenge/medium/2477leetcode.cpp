#include <bits/stdc++.h>
using namespace std;

long long ans = 0;
long long minimumFuelCost(vector<vector<int>> &roads, int seats)
{
    vector<vector<int>> a(roads.size() + 1);
    for (auto &x : roads)
    {
        a[x[0]].push_back(x[1]);
        a[x[1]].push_back(x[0]);
    }
    helper(0, -1, a, seats);
    return ans;
}
int helper(int node, int parent, vector<vector<int>> &a, int seats)
{
    int ppl = 1;
    for (auto &child : a[node])
    {
        if (child != parent)
        {
            ppl += helper(child, node, a, seats);
        }
    }
    if (node != 0)
    {
        ans += ceil((double)ppl / seats);
    }
    return ppl;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> roads(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        cin >> roads[i][0] >> roads[i][1] >> roads[i][2];
    }
    int seats;
    cin >> seats;
    cout << minimumFuelCost(roads, seats);
    return 0;
}