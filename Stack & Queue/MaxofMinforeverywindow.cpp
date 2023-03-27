#include <bits/stdc++.h>
using namespace std;
vector<int> maxOfMin(int arr[], int n)
{
    // Your code here
    stack<int> st;
    int left[n + 1];
    int right[n + 1];
    for (int i = 0; i < n; i++)
    {
        left[i] = -1;
        right[i] = n;
    }

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            left[i] = st.top();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        st.pop();
    }

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            right[i] = st.top();
        }
        st.push(i);
    }
    vector<int> ans(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        int len = right[i] - left[i] - 1;
        ans[len] = max(ans[len], arr[i]);
    }

    for (int i = n - 1; i >= 1; i--)
    {
        ans[i] = max(ans[i], ans[i + 1]);
    }

    vector<int> res(n);
    for (int i = 1; i <= n; i++)
    {
        res[i - 1] = ans[i];
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> ans = maxOfMin(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}