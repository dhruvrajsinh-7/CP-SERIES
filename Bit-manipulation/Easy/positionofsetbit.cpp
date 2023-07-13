#include <bits/stdc++.h>
using namespace std;
int findPosition(int N)
{
    // code here
    int res = -1, i = 0;
    while (N)
    {
        i++;
        if (N & 1 == 1)
        {
            if (res != -1)
                return -1;
            res = i;
        }
        N = N >> 1;
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    cout << findPosition(n) << endl;
    return 0;
}