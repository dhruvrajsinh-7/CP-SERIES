#include <bits/stdc++.h>
using namespace std;
string maxn;
string swap(string str, int i, int j)
{
    char x = str[i];
    str[i] = str[j];
    str[j] = x;
    return str;
}
void findmax(int idx, string str, int k)
{
    if (str.compare(maxn) > 0)
    {
        maxn = str;
    }
    if (k == 0)
    {
        return;
    }
    for (int i = idx; i < str.size() - 1; i++)
    {
        for (int j = i + 1; j < str.size(); j++)
        {
            if (str[i] < str[j])
            {
                str = swap(str, i, j);
                findmax(i + 1, str, k - 1);
                str = swap(str, i, j);
            }
        }
    }
}
string findMaximumNum(string str, int k)
{
    // code here.
    maxn = str;
    findmax(0, str, k);
    return maxn;
}
int main()
{
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    cout << findMaximumNum(str, k);
    return 0;
}