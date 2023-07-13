#include <bits/stdc++.h>
using namespace std;
int countBitsFlip(int a, int b)
{
    // Your logic here
    int N = a ^ b;
    int cnt = 0;
    while (N != 0)
    {
        N = N & (N - 1);
        cnt++;
    }
    return cnt;
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << countBitsFlip(a, b) << endl;
    return 0;
}