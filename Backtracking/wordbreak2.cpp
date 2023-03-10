#include <bits/stdc++.h>
using namespace std;
vector<string> res;
int isdictcontain(int n, string word, vector<string> dict)
{

    for (int i = 0; i < n; i++)
    {
        if (dict[i].compare(word) == 0)
        {
            return 1;
        }
    }
    return 0;
}
void solve(int n, vector<string> dict, string s, string ans)
{
    if (s.length() == 0)
    {
        int len = ans.length();
        ans = ans.substr(0, len - 1);
        res.push_back(ans);
        return;
    }
    for (int i = 0; i < s.length(); i++)
    {
        string left = s.substr(0, i + 1);
        if (isdictcontain(n, left, dict) == 1)
        {
            string right = s.substr(i + 1);
            solve(n, dict, right, ans + left + " ");
        }
    }
}
vector<string> wordBreak(int n, vector<string> &dict, string s)
{
    // code here
    res.clear();
    solve(n, dict, s, "");
    return res;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> dict(n);
        for (int i = 0; i < n; i++)
        {
            cin >> dict[i];
        }
        string s;
        cin >> s;
        vector<string> ans = wordBreak(n, dict, s);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << "(" << ans[i] << ")";
        }
        cout << endl;
    }
}