#include <bits/stdc++.h>
using namespace std;
int setBits(int N)
{
    // Write Your Code here
    int setBits = 0;

    while (N > 0)
    {
        N = N & (N - 1);
        setBits++;
    }

    return setBits;
}
int main()
{
    int n;
    cin >> n;
    cout << setBits(n) << endl;
    return 0;
}