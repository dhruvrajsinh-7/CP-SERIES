#include <bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k)
{
    int i = 0, j = 0, maxFreq = 0, maxLen = 0;
    unordered_map<char, int> mp;
    while (j < s.size())
    {
        mp[s[j]]++;
        maxFreq = max(maxFreq, mp[s[j]]);
        if ((j - i + 1) - maxFreq <= k)
        {
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        else if ((j - i + 1) - maxFreq > k)
        {
            while ((j - i + 1) - maxFreq > k)
            {
                mp[s[i]]--;
                i++;
            }
            j++;
        }
    }
    return maxLen;
}
int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    cout << characterReplacement(s, k);
    return 0;
}