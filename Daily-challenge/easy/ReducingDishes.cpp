#include <bits/stdc++.h>
using namespace std;
struct comp
{
    bool operator()(int const &i, int const &j) const
    {
        return i > j;
    }
};
int maxSatisfaction(vector<int> &satisfaction)
{
    sort(satisfaction.begin(), satisfaction.end(), comp());
    int curr_sum = 0;
    int n = satisfaction.size();
    int res = 0;
    int curr = 0;
    for (int i = 0; i < n; i++)
    {
        curr += curr_sum + satisfaction[i];
        curr_sum += satisfaction[i];
        res = max(res, curr);
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    vector<int> satisfaction(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> satisfaction[i];
    }
    cout << maxSatisfaction(satisfaction);
    return 0;
}