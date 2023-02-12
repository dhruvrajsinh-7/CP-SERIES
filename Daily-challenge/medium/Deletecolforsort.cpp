#include <bits/stdc++.h>
using namespace std;
int minDeletionSize(vector<string> &strs)
{
    int i = 0, j, count = 0;
    for (i = 0; i < strs[0].size(); i++)
    {
        for (j = 1; j < strs.size(); j++)
        {
            if (strs[j][i] < strs[j - 1][i])
            {
                count++;
                break;
            }
        }
    }
    return count;
}
int main()
{
    vector<string> strs;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        strs.push_back(s);
    }
    cout << minDeletionSize(strs);
    return 0;
}