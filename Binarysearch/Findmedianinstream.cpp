#include <bits/stdc++.h>
using namespace std;
priority_queue<int> s;
priority_queue<int, vector<int>, greater<int>> g;
// Function to insert heap.
void insertHeap(int &x)
{
    if (s.size() == 0)
    {
        s.push(x);
        return;
    }
    if (s.size() > g.size())
    {
        if (x < s.top())
        {
            g.push(s.top());
            s.pop();
            s.push(x);
        }
        else
        {
            g.push(x);
        }
    }
    else
    {
        if (x < s.top())
        {
            s.push(x);
        }
        else
        {
            g.push(x);
            s.push(g.top());
            g.pop();
        }
    }
}

double getMedian()
{
    if (s.size() == g.size())
    {
        return (double)(s.top() + g.top()) / 2.0;
    }
    else
    {
        return s.top();
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        insertHeap(A[i]);
        cout << getMedian() << endl;
    }
    return 0;
}