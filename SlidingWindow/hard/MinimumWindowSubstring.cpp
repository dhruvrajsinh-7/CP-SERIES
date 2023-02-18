#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s, t;
    cin >> s >> t;
    minWindow(s, t);
    return 0;
}
string minWindow(string s, string t)
{
    unordered_map<char, int> map;
    if (s.size() < t.size())
    {
        return "";
    }
    for (int i = 0; i < t.size(); i++)
    {
        map[t[i]]++;
    }
    int i = 0, j = 0, mn = INT_MAX, count = 0;
    string ans = "";

    count = map.size();
    while (j < s.size())
    {
        if (map.find(s[j]) != map.end())
        {
            map[s[j]]--;
            if (map[s[j]] == 0)
            {
                count--;
            }
        }
        if (count == 0)
        {
            if (mn > j - i + 1)
            {
                mn = j - i + 1;
                ans = s.substr(i, mn);
            }
            while (i <= j && count == 0)
            {
                if (map.find(s[i]) != map.end())
                {
                    map[s[i]]++;

                    if (map[s[i]] == 1)
                    {
                        if (mn > j - i + 1)
                        {
                            mn = j - i + 1;
                            ans = s.substr(i, mn);
                        }
                        count++;
                    }
                }
                i++;
            }
        }
        j++;
    }
    if (mn == INT_MAX)
    {
        return "";
    }
    return ans;
}