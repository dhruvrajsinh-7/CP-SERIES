#include <bits/stdc++.h>
using namespace std;
vector<string> AllPossibleStrings(string s)
{

    vector<string> v;
    int n = s.length();

    for (int num = 0; num < pow(2, n); num++)
    {
        string sub;
        for (int i = 0; i < n; i++)
        {
            if (num & 1 << i)
            {
                sub = sub + s[i];
            }
        }
        if (!sub.empty())
            v.push_back(sub);
    }
    sort(v.begin(), v.end());
    return v;
}
int main()
{
    string s = "abc";
    vector<string> v = AllPossibleStrings(s);
    for (auto i : v)
        cout << i << " ";
    return 0;
}