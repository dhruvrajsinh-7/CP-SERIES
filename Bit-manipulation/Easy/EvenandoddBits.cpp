#include <bits/stdc++.h>
using namespace std;
vector<int> evenOddBit(int n)
{
    int cte = 0, cto = 0, i = 0;
    while (n != 0)
    {
        if (i % 2 == 0 and (n & 1) == 1)
            cte++;
        if (i % 2 != 0 and (n & 1) == 1)
            cto++;
        i++;
        n = n >> 1;
    }
    return {cte, cto};
}
int main()
{
    int n;
    cin >> n;
    vector<int> ans = evenOddBit(n);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}