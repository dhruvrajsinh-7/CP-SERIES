#include <bits/stdc++.h>
using namespace std;
string mergeAlternately(string word1, string word2)
{
    int i = 0, j = 0;
    string ans = "";
    int n = word1.size();
    int m = word2.size();
    while (i < n || j < m)
    {
        if (i < n)
        {
            ans.push_back(word1[i++]);
        }
        if (j < m)
        {
            ans.push_back(word2[j++]);
        }
    }
    return ans;
}
int main()
{
    string s1 = "abc";
    string s2 = "pqr";
    cout << mergeAlternately(s1, s2);
    return 0;
}
