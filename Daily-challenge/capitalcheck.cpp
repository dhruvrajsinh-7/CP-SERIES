#include<bits/stdc++.h>
using namespace std;
bool detectCapitalUse(string word)
{
    if (word.size() == 1)
    {
        return true;
    }
    int i = 0, count = 0;
    while (i < word.size())
    {
        if (isupper(word[i]))
        {
            count++;
        }
        i++;
    }
    if (count == 1 && isupper(word[0]) || count == 0 || count == word.size())
    {
        return true;
    }
    return false;
}
int main()
{
    string word;
    cin >> word;
    if (detectCapitalUse(word))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}