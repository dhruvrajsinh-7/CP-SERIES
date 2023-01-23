#include<bits/stdc++.h>
using namespace std;
int findJudge(int n, vector<vector<int>> &trust)
{
    vector<int> in(n + 1, 0);
    vector<int> out(n + 1, 0);
    if (n == 1)
    {
        return 1;
    }
    for (auto it : trust)
    {
        out[it[0]]++;
        in[it[1]]++;
    }
    for (int i = 0; i <= n; i++)
    {
        if (out[i] == 0 && in[i] == n - 1)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int n = 2;
    vector<vector<int>> trust = {{1, 2}};
    cout << findJudge(n, trust);
    return 0;
}