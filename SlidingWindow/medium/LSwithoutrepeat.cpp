#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    long long i, j, res = INT_MIN;
    int n = s.size();
    i = j = 0;
    map<char, int> mp;
    if (n == 0)
        return 0;
    while (j < n)
    {
        mp[s[j]]++;
        if (mp[s[j]] == 1)
            res = max(res, j - i + 1);

        else if (mp[s[j]] > 1)
        {
            while (mp[s[j]] > 1)
            {
                mp[s[i]]--;
                ++i;
                if (mp[s[j]] == 1)
                    res = max(res, j - i + 1);
            }
        }
        ++j;
    }
    return res;
}
int main()
{
    string s;
    cin >> s;
    cout << lengthOfLongestSubstring(s);
    return 0;
}
