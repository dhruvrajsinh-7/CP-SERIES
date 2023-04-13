#include <bits/stdc++.h>
using namespace std;
bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
{
    stack<int> st;
    int i = 0;
    for (auto it : pushed)
    {
        st.push(it);
        while (i < popped.size() && !st.empty() && popped[i] == st.top())
        {
            st.pop();
            i++;
        }
    }
    return st.empty();
}
int main()
{
    vector<int> pushed = {1, 2, 3, 4, 5};
    vector<int> popped = {4, 5, 3, 2, 1};
    cout << validateStackSequences(pushed, popped);
    return 0;
}