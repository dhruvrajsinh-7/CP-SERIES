#include <bits/stdc++.h>
using namespace std;
stack<long long int> s;
long long int minele = 1e12;
void push(int val)
{
    if (s.size() == 0)
    {
        s.push(val);
        minele = val;
    }
    else
    {
        if (val >= minele)
        {
            s.push(val);
        }
        else if (val < minele)
        {
            s.push((long long)2 * val - minele);
            minele = val;
        }
    }
}

void pop()
{
    if (s.size() == 0)
    {
        return;
    }
    else
    {
        if (s.top() >= minele)
        {
            s.pop();
        }
        else if (s.top() < minele)
        {
            minele = 2 * minele - s.top();
            s.pop();
        }
    }
}

int top()
{
    if (s.empty())
    {
        return -1;
    }
    else
    {
        if (s.top() >= minele)
        {
            return s.top();
        }
        else if (s.top() < minele)
        {
            return minele;
        }
    }
    return s.top();
}

int getMin()
{
    if (s.size() == 0)
    {
        return -1;
    }
    return minele;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        push(val);
    }
    cout << getMin() << endl;
    pop();
    cout << getMin() << endl;
}