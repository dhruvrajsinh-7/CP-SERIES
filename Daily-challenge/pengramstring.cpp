#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    return checkIfPangram(s);
}
bool checkIfPangram(string s1)
{
    set<int> s;
    for (auto &c1 : s1)
        s.insert(c1);
    if (s.size() == 26)
        return true;
    return false;
}
