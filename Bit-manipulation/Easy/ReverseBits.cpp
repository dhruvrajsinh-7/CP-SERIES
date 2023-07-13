#include <bits/stdc++.h>
using namespace std;
uint32_t reverseBits(uint32_t n)
{
    uint32_t res = 0;
    for (int i = 0; i < 31; i++)
    {
        res = (n % 2) + res << 1;
        n = n >> 1;
    }
    return res + n % 2;
}
int main()
{
    uint32_t n;
    cin >> n;
    cout << reverseBits(n) << endl;
    return 0;
}