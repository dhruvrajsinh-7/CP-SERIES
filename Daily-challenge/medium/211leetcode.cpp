#include <bits/stdc++.h>
using namespace std;
unordered_map<int, vector<string>> mp;

bool check(string &str1, string &str2)
{
    for (int i = 0; i < str1.size(); i++)
    {
        if (str2[i] == '.')
        {
            continue;
        }
        if (str1[i] != str2[i])
        {
            return false;
        }
    }
    return true;
}
void addWord(string word)
{
    mp[word.size()].push_back(word);
}

bool search(string word)
{
    for (auto &s : mp[word.size()])
    {
        if (check(s, word))
        {
            return true;
        }
    }
    return false;
}
int main()
{

    addWord("bad");
    addWord("dad");
    addWord("mad");
    // addWord("pad");
    cout << search("cad") << endl;
    cout << search("pad") << endl;
    cout << search("bad") << endl;
    cout << search(".ad") << endl;
    cout << search("b..") << endl;
    return 0;
}