#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s = "abba";
    string ans = makeGood(s);
    cout << ans;
}
string makeGood(string s)
{
    vector<char> st;
    for (auto it : s)
    {
        if (!st.empty() && abs(st.back() - it) == 32)
        {
            st.pop_back();
        }
        else
        {
            st.push_back(it);
        }
    }
    string ans(st.begin(), st.end());
    return ans;
}