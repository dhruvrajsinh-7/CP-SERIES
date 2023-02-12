#include <iostream>
using namespace std;
string breakPalindrome(string s)
{
    if (s.size() == 1)
        return "";
    for (int i = 0; i < s.size() / 2; i++)
    {
        if (s[i] != 'a')
        {
            s[i] = 'a';
            return s;
        }
    }
    s[s.size() - 1] = 'b';
    return s;
}
int main()
{
    string s;
    cin >> s;
    cout << breakPalindrome(s);
    return 0;
}
