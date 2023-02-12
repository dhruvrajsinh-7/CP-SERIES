#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    cout << reverseword(s);
    return 0;
}
string reverseword(string s)
{
    string ans;
    int n = s.size();
    int i = 0;
    while (i < n)
    {
        while (i < n && s[i] == ' ')
        {
            i++;
        }
        if (i >= n)
        {
            break;
        }
        int j = i;
        while (j < n && s[j] != ' ')
            j++;

        string sub = s.substr(i, j - i);

        if (ans.size() == 0)
        {
            ans = sub;
        }
        else
        {
            ans = sub + " " + ans;
        }
        i = j + 1;
    }
    return ans;
}