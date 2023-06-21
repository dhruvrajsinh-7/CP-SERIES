#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;

bool helper(string &s, int i, int j, vector<string> &dict)
{
    if (dp[i][j] != -1)
        return dp[i][j];

    if (find(dict.begin(), dict.end(), s.substr(i, j - i + 1)) != dict.end())
        return dp[i][j] = true;

    for (int k = i + 1; k <= j; k++)
    {
        if (helper(s, i, k - 1, dict) and helper(s, k, j, dict))
            return dp[i][j] = true;
    }

    return dp[i][j] = false;
}

bool wordBreak(string s, vector<string> &dict)
{
    int n = s.size();

    int i = 0;
    int j = s.size() - 1;

    dp.resize(n + 1, vector<int>(n + 1, -1));

    return helper(s, i, j, dict);
}
int main()
{
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<string> dict(n);
    for (int i = 0; i < n; i++)
        cin >> dict[i];
    cout << wordBreak(s, dict) << endl;
    return 0;
}