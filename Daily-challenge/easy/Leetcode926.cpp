#include <bits/stdc++.h>
using namespace std;

int minFlipsMonoIncr(string s)
{
    int n_flip = 0, n_one = 0;
    for (auto i : s)
    {
        if (i == '1')
        {
            n_one++;
        }
        else
        {
            n_flip++;
        }
        n_flip = min(n_one, n_flip);
    }
    return n_flip;
}
int main()
{
    string s;
    cin >> s;
    cout << minFlipsMonoIncr(s);
    return 0;
}
