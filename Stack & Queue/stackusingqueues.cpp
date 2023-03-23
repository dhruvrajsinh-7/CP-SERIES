#include <bits/stdc++.h>
using namespace std;
queue<int> q;
int n;
void push(int x)
{
    n = q.size();
    q.push(x);
    for (int i = 0; i < n; i++)
    {
        q.push(q.front());
        q.pop();
    }
}

int pop()
{
    int x = q.front();
    q.pop();
    return x;
}

int top()
{
    int x = q.front();
    return x;
}

bool empty()
{
    return q.empty();
}
int main()
{
    push(1);
    push(2);
    push(3);
    cout << top() << endl;
    cout << pop() << endl;
    cout << top() << endl;
    cout << pop() << endl;
    cout << top() << endl;
    cout << pop() << endl;
    cout << empty() << endl;
    return 0;
}