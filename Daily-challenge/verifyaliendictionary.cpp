#include <bits/stdc++.h>
using namespace std;
bool isAlienSorted(vector<string> &words, string order)
{
    map<char, char> ascii;
    int n = order.size();
    for (int i = 0; i < n; i++)
    {
        ascii[order[i]] = i + 'a';
    }
    for (auto &word : words)
    {
        for (auto &ch : word)
        {
            ch = ascii[ch];
        }
    }
    return is_sorted(words.begin(), words.end());
}
int main()
{
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }
    string order;
    cin >> order;
    cout << isAlienSorted(words, order);
    return 0;
}