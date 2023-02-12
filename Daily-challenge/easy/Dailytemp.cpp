#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> temp(n);
    for (int i = 0; i < n; i++)
    {
        cin >> temp[i];
    }
    vector<int> ans = dailyTemperatures(temp);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
vector<int> dailyTemperatures(vector<int> &temperatures)
{
    int n = temperatures.size();
    vector<int> g(n, 0);
    stack<int> st;
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && temperatures[st.top()] <= temperatures[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            g[i] = st.top() - i;
        }
        st.push(i);
    }
    return g;
}