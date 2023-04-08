#include <bits/stdc++.h>
using namespace std;
int minimumCostOfBreaking(vector<int> x, vector<int> y, int M, int N)
{
    // Write your code here
    int h = 1, v = 1;
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    int i = M - 2, j = N - 2, ans = 0;
    while (i > -1 && j > -1)
    {
        if (x[i] > y[j])
        {
            ans += x[i] * h;
            v++;
            i--;
        }
        else
        {
            ans += y[j] * v;
            h++;
            j--;
        }
    }
    if (i == -1)
    {
        while (j > -1)
        {
            ans += y[j] * v;
            j--;
        }
    }
    if (j == -1)
    {
        while (i > -1)
        {
            ans += x[i] * h;
            i--;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];
    int m;
    cin >> m;
    vector<int> y(m);
    for (int i = 0; i < m; i++)
        cin >> y[i];
    cout << minimumCostOfBreaking(x, y, n, m);
    return 0;
}