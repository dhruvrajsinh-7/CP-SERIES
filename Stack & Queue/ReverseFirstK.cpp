#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k)
{
    stack<int> st;
    for (int i = 0; i < k; i++)
    {
        st.push(q.front());
        q.pop();
    }
    queue<int> res;
    while (!st.empty())
    {
        res.push(st.top());
        st.pop();
    }
    while (!q.empty())
    {
        res.push(q.front());
        q.pop();
    }
    return res;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> a = modifyQueue(q, k);
        while (!a.empty())
        {
            cout << a.front() << " ";
            a.pop();
        }
        cout << endl;
    }
    return 0;
}