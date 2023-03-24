#include <bits/stdc++.h>
using namespace std;
int isStackPermutation(int n, vector<int> &a, vector<int> &b)
{
    int i = 0, j = 0;
    stack<int> st;

    while (i < n && j < n)
    {
        if (a[i] != b[j])
        {
            st.push(a[i]);
            i++;
        }
        else
        {
            st.push(a[i]);
            i++;
            while (!st.empty() && st.top() == b[j])
            {
                st.pop();
                j++;
            }
        }
    }
    return st.empty();
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    cout << isStackPermutation(n, a, b) << endl;
    return 0;
}