#include <bits/stdc++.h>
using namespace std;
string smallestNumber(int S, int D)
{
    // code here
    if (9 * D < S)
    {
        return "-1";
    }
    string res = "";
    for (int i = D - 1; i >= 0; i--)
    {
        if (S > 9)
        {
            res = '9' + res;
            S -= 9;
        }
        else
        {
            if (i == 0)
            {
                res = to_string(S) + res;
            }
            else
            {
                res = to_string(S - 1) + res;
                i--;
                while (i > 0)
                {
                    res = '0' + res;
                    i--;
                }
                res = '1' + res;
                break;
            }
        }
    }
    return res;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int s, d;
        cin >> s >> d;
        cout << smallestNumber(s, d) << endl;
    }
    return 0;
}