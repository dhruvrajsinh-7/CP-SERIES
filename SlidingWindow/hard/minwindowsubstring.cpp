#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t)
{
    if (t == "")
    {
        return "";
    }
    unordered_map<char, int> map, window;
    for (auto it : t)
    {
        map[it]++;
    }
    int require = map.size(), have = 0;
    string res = "";
    int min_l = INT_MAX, m_pos = -1;
    int i = 0, j = 0;
    char c;
    while (j < s.size())
    {
        c = s[j];
        window[c]++;
        if (map.find(c) != map.end() and window[c] == map[c])
        {
            have++;
        }
        while (have == require)
        {
            if (j - i + 1 < min_l)
            {
                min_l = j - i + 1;
                m_pos = i;
            }
            window[s[i]]--;
            if (map.find(s[i]) != map.end() and window[s[i]] < map[s[i]])
                have--;
            i++;
        }
        j++;
    }
    if (min_l < INT_MAX)
        res = s.substr(m_pos, min_l);
    return res;
}
int main()
{
    string s, t;
    cin >> s >> t;
    cout << minWindow(s, t);
    return 0;
}