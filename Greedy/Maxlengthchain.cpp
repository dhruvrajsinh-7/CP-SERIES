#include <bits/stdc++.h>
using namespace std;
static bool cmp(struct val a, struct val b)
{
    return a.second < b.second;
}
/*You are required to complete this method*/
int maxChainLen(struct val p[], int n)
{
    // Your code here
    sort(p, p + n, cmp);
    int ans = 0;
    int prev = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (p[i].first > prev)
        {
            ans++;
            prev = p[i].second;
        }
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        struct val p[n];
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            p[i].first = x;
            p[i].second = y;
        }
        cout << maxChainLen(p, n) << endl;
    }
    return 0;
}