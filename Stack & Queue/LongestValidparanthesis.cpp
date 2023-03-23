#include <bits/stdc++.h>
using namespace std;

int maxLength(string S)
{
    // code here
    int n = S.size();
    int left = 0, right = 0, max_len = 0;
    for (int i = 0; i < n; i++)
    {
        if (S[i] == '(')
        {
            left++;
        }
        else
        {
            right++;
        }

        if (left == right)
        {
            max_len = max(max_len, 2 * right);
        }
        else if (right > left)
        {
            left = 0;
            right = 0;
        }
    }
    left = 0, right = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (S[i] == '(')
        {
            left++;
        }
        else
        {
            right++;
        }
        if (left == right)
        {
            max_len = max(max_len, 2 * left);
        }
        else if (left > right)
        {
            left = right = 0;
        }
    }
    return max_len;
}
int main()
{
    string s;
    cin >> s;
    cout << maxLength(s);
    return 0;
}