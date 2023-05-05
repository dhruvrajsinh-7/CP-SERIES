#include <bits/stdc++.h>
using namespace std;
int maxVowels(string s, int k)
{
    unordered_set<char> vowel = {'a', 'e', 'i', 'o', 'u'};
    int i = 0, cnt = 0, res = 0, l = 0;
    for (int r = 0; r < s.length(); r++)
    {
        cnt += (vowel.find(s[r]) != vowel.end()) ? 1 : 0;
        if (r - l + 1 > k)
        {
            cnt -= (vowel.find(s[i]) != vowel.end()) ? 1 : 0;
            i++;
            l++;
        }
        res = max(res, cnt);
    }
    return res;
}
int main()
{
    string s = "abciiidef";
    int k = 3;
    cout << maxVowels(s, k);
    return 0;
}