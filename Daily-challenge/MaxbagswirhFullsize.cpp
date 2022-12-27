#include <bits/stdc++.h>
using namespace std;
int maximumBags(vector<int> &capacity, vector<int> &rocks, int additional)
{
    vector<int> ans;
    int res;
    int n = capacity.size();
    for (int i = 0; i < n; i++)
    {
        ans.push_back(capacity[i] - rocks[i]);
    }
    sort(ans.begin(), ans.end());
    for (res = 0; res < n && additional >= ans[res]; res++)
        additional = additional - ans[res];
    return res;
}
int main()
{
    int n;
    cin >> n;
    vector<int> capacity(n);
    vector<int> rocks(n);
    for (int i = 0; i < n; i++)
    {
        cin >> capacity[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> rocks[i];
    }
    int additional;
    cin >> additional;
    cout << maximumBags(capacity, rocks, additional);
    return 0;
}