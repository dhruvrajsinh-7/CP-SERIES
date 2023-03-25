#include <bits/stdc++.h>
using namespace std;
int celebrity(vector<vector<int>> &M, int n)
{
    // code here
    stack<int> st;
    for (int i = 0; i < M.size(); i++)
    {
        st.push(i);
    }
    while (st.size() >= 2)
    {
        int i = st.top();
        st.pop();
        int j = st.top();
        st.pop();
        if (M[i][j] == 0)
        {
            st.push(i);
        }
        else
        {
            st.push(j);
        }
    }
    int ans = st.top();
    for (int i = 0; i < M.size(); i++)
    {
        if (i != ans)
        {
            if (M[i][ans] == 0 || M[ans][i] == 1)
            {
                return -1;
            }
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> M(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> M[i][j];
        }
    }
    cout << celebrity(M, n) << endl;
    return 0;
}