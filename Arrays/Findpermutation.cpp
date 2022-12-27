#include <bits/stdc++.h>
using namespace std;
void helper(string s, int start, int end, vector<string> &ans)
{
    if (start == end)
    {
        ans.push_back(s);
    }
    for (int i = start; i <= end; i++)
    {
        if (s[i] == s[i - 1])
        {
            continue;
        }
        swap(s[start], s[i]);
        helper(s, start + 1, end, ans);
        swap(s[start], s[i]);
    }
}
vector<string> find_permutation(string S)
{
    // Code here there
    vector<string> ans;
    helper(S, 0, S.size() - 1, ans);
    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{
    string s;
    cin >> s;
    vector<string> ans = find_permutation(s);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}