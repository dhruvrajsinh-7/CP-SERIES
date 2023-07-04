#include <bits/stdc++.h>
using namespace std;
struct Job
{
    int id;
    int dead;
    int profit;
};
static bool cmp(Job a, Job b)
{
    return a.profit > b.profit;
}
vector<int> JobScheduling(Job arr[], int n)
{
    // your code here
    sort(arr, arr + n, cmp);
    int maxx = arr[0].dead;
    for (int i = 0; i < n; i++)
    {
        maxx = max(maxx, arr[i].dead);
    }
    int slot[maxx + 1];
    for (int i = 0; i <= maxx; i++)
    {
        slot[i] = -1;
    }
    int cnt = 0, profit = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].dead; j > 0; j--)
        {
            if (slot[j] == -1)
            {
                slot[j] = i;
                cnt++;
                profit += arr[i].profit;
                break;
            }
        }
    }
    vector<int> ans;
    ans.push_back(cnt);
    ans.push_back(profit);
    return ans;
}
int main()
{
    int n;
    cin >> n;
    Job arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].id >> arr[i].dead >> arr[i].profit;
    }
    vector<int> ans = JobScheduling(arr, n);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}