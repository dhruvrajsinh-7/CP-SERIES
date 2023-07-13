#include <bits/stdc++.h>
using namespace std;
vector<int> countBits(int n)
{
    vector<int> ans(n + 1, 0);
    for (int i = 0; i <= n; i++)
    {
        long long count = 0, j = i;
        while (j != 0)
        {
            j &= (j - 1);
            count++;
        }
        ans[i] = count;
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> ans = countBits(n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}