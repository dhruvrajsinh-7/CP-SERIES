#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int countSetBits(int n)
{
    if ((n & (n - 1)) == 0)
    {
        return 1 + log2(n) * (n / 2);
    }
    else
    {
        int y = pow(2, (int)log2(n));
        return (n - y) + countSetBits(y) + countSetBits(n - y);
    }
}
int main()
{
    int n;
    cin >> n;
    cout << countSetBits(n) << endl;
    return 0;
}