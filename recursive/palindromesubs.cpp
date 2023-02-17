#include <bits/stdc++.h>
using namespace std;
int c = 0;
bool ispalindrome(string s, int l, int r)
{
    while (l >= 0 && r < s.size() && s.at(l) == s.at(r))
    {
        c++;
        l--;
        r++;
    }
    return c;
}
int countSubstrings(string s)
{

    for (int i = 0; i < s.size(); i++)
    {
        ispalindrome(s, i, i);
        ispalindrome(s, i, i + 1);
    }
    return c;
}

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << countSubstrings(s);
    return 0;
}