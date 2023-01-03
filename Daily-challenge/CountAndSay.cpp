#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string ans = countAndSay(n);
    cout << ans;
    return 0;
}
string helper(int n, string s = "1")
{
    if (n == 1)
    {
        return s;
    }
    int i = 0, j, size = s.size();
    string ans = "";
    while (i < size)
    {
        j = i;
        while (i < size && s[i] == s[j])
        {
            i++;
        }
        ans += to_string(i - j) + s[j];
    }
    return helper(n - 1, ans);
}
string countAndSay(int n)
{
    return helper(n, "1");
}