#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        stack<char> st;
        int flag = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ')')
            {
                if (st.top() == '(')
                {
                    flag = 1;
                    break;
                }
                else
                {
                    while (st.top() != '(')
                    {
                        st.pop();
                    }
                    st.pop();
                }
            }
            else
            {
                st.push(s[i]);
            }
        }
        if (flag == 1)
        {
            cout << "Duplicate" << endl;
        }
        else
        {
            cout << "Not Duplicates" << endl;
        }
    }
    return 0;
}