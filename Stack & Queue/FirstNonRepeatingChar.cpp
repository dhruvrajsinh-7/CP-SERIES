#include <bits/stdc++.h>
using namespace std;
string FirstNonRepeating(string A)
{
    queue<int> q;
    string dummy = "";
    vector<int> arr(26, 0);
    for (auto it : A)
    {
        arr[it - 'a']++;
        if (arr[it - 'a'] == 1)
        {
            q.push(it);
        }
        while (!q.empty() && arr[q.front() - 'a'] != 1)
        {
            q.pop();
        }
        if (q.empty())
        {
            it = '#';
        }
        else
        {
            it = q.front();
        }
        dummy += it;
    }
    A = dummy;
    return A;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string A;
        cin >> A;
        cout << FirstNonRepeating(A) << endl;
    }
    return 0;
}