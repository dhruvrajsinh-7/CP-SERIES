#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<string> words(m);
    for (int i = 0; i < m; i++)
    {
        cin >> words[i];
    }
    vector<string> result = findAllConcatenatedWordsInADict(words);
    for (auto it : result)
    {
        cout << it << " ";
    }
    return 0;
}
unordered_set<string> set;
vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
{
    vector<string> result;
    unordered_set<string>set (words.begin(), words.end());

    for (auto word : words)
    {
        if (helperconcat(word,set))
        {
            result.push_back(word);
        }
    }
    return result;
}
bool helperconcat(string word, unordered_set<string> &set)
{
    for (int i = 1; i < word.size(); i++)
    {
        string prefix = word.substr(0, i);
        string suffix = word.substr(i, word.size() - i);
        if (set.find(prefix) != set.end() && (set.find(suffix) != set.end() || helperconcat(suffix,set)))
        {
            return true;
        }
    }
    return false;
}