#include <bits/stdc++.h>
using namespace std;
bool buddyStrings(string s, string goal)
{
    if (s.size() < goal.size() || goal.size() < s.size())
    {
        return false;
    }
    if (s == goal)
    {
        unordered_map<char, int> different;
        for (int i = 0; i < s.size(); i++)
        {
            different[s[i]]++;
            if (different[s[i]] > 1)
            {
                return true;
            }
        }
        return false;
    }
    vector<int> different;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != goal[i])
        {
            different.push_back(i);
            if (different.size() > 2)
            {
                return false;
            }
        }
    }
    if (different.size() != 2)
    {
        return false;
    }
    if ((s[different[0]] == goal[different[1]]) && (s[different[1]] == goal[different[0]]))
        return true;

    return false;
}