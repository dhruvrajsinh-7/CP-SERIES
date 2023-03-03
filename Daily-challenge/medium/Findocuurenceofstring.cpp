#include <bits/stdc++.h>
using namespace std;

int strStr(string haystack, string needle)
{
    int n = haystack.size();
    int m = needle.size();
    if (m == 0)
        return 0;
    vector<int> lps = findlps(needle, m);
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (haystack[i] == needle[j])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            return i - j;
        }
        else if (i < n && j < m && haystack[i] != needle[j])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
    return -1;
}
vector<int> findlps(string needle, int m)
{
    int len = 0;
    int i = 1;
    vector<int> lps(m, 0);
    while (i < m)
    {
        if (needle[i] == needle[len])
        {
            len++;
            lps[i++] = len;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i++] = 0;
            }
        }
    }
    return lps;
}
int main()
{
    string haystack, needle;
    cin >> haystack >> needle;
    cout << strStr(haystack, needle);
    return 0;
}