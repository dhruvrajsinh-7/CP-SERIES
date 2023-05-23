#include <bits/stdc++.h>
using namespace std;
int maxLen(vector<int> &A, int n)
{
    unordered_map<int, int> mp;
    int max_len = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += A[i];
        if (sum == 0)
        {
            max_len = i + 1;
        }
        if (mp.find(sum) != mp.end())
        {
            max_len = max(max_len, i - mp[sum]);
        }
        else
        {
            mp[sum] = i;
        }
    }
    return max_len;
}
int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i)

        cin >> A[i];

    cout << maxLen(A, n);

    return 0;
}
