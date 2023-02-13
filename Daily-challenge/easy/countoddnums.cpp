#include <bits/stdc++.h>
using namespace std;

int countOdds(int low, int high)
{
    int count = 0;
    if (low % 2 == 0)
    {
        low++;
    }
    while (low < high)
    {
        low = low + 2;
        count++;
    }
    if (high % 2 != 0)
    {
        count++;
    }
    return count;
}
int main()
{
    int s, e;
    cin >> s >> e;
    cout << countOdds(s, e);
    return 0;
}